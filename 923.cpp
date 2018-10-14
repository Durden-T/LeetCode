#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iterator>
#include <numeric>
#include <bitset>

using namespace std;

static int __initialSetup = []() {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> triples;
        sort(nums.begin(), nums.end());
        int i = 0, last = nums.size() - 1;
        while (i < last)
        {
            int a = nums[i], j = i + 1, k = last;
            while (j < k)
            {
                int b = nums[j], c = nums[k], sum = a + b + c;
                if (!sum)
                    triples.push_back({a, b, c});
                if (sum <= 0)
                    while (nums[j] == b && j < k)
                        ++j;
                if (sum >= 0)
                    while (nums[k] == c && j < k)
                        --k;
            }
            while (nums[i] == a && i < last)
                ++i;
        }
        return triples;
    }
};

class Solution
{
    const int MOD = 1000000007;

  public:
    int threeSumMulti(vector<int> &A, int target)
    {
        int choose = 0;
        if (choose == 0)
        {
            long long ans = 0;
            vector<int> m(101, 0);
            for (int i : A)
                ++m[i];
            for (int i = 0; i < A.size() - 2; ++i)
            {
                --m[A[i]];
                vector<int> tm(m);
                for (int j = i + 1; j < A.size() - 1; ++j)
                {
                    --tm[A[j]];
                    int t = target - A[i] - A[j];
                    if (t >= 0 && t <= 100 && tm[t] > 0)
                    {
                        ans += tm[t];
                        ans %= MOD;
                    }
                }
            }
            return ans;
        }

        else if (choose == 1)
        {
            long long ans = 0;
            sort(A.begin(), A.end());

            for (int i = 0; i < A.size(); ++i)
            {
                // We'll try to find the number of i < j < k
                // with A[j] + A[k] == T, where T = target - A[i].

                // The below is a "two sum with multiplicity".
                int T = target - A[i];
                int j = i + 1, k = A.size() - 1;

                while (j < k)
                {
                    // These steps proceed as in a typical two-sum.
                    if (A[j] + A[k] < T)
                        ++j;
                    else if (A[j] + A[k] > T)
                        --k;
                    else if (A[j] != A[k])
                    { // We have A[j] + A[k] == T.
                        // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                        // And similarly for "right".
                        int left = 1, right = 1;
                        while (j + 1 < k && A[j] == A[j + 1])
                        {
                            ++left;
                            ++j;
                        }

                        while (k - 1 > j && A[k] == A[k - 1])
                        {
                            ++right;
                            --k;
                        }

                        ans += left * right;
                        ans %= MOD;
                        ++j;
                        --k;
                    }
                    else
                    {
                        // M = k - j + 1
                        // We contributed M * (M-1) / 2 pairs.
                        ans += (k - j + 1) * (k - j) / 2;
                        ans %= MOD;
                        break;
                    }
                }
            }

            return ans;
        }

        else if (choose == 2)
        {

            long long m[101] = {}, ans = 0;
            for (int n : A)
                ++m[n];
            for (int i = 0; i < 101; ++i)
            {
                if (i * 3 == target)
                {
                    ans += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
                    ans %= MOD;
                }

                for (int j = i + 1; j < 101; ++j)
                {
                    if (i * 2 + j == target) // i == j != k
                    {
                        ans += m[i] * m[j] * (m[i] - 1) / 2;
                        ans %= MOD;
                    }
                    if (i + j * 2 == target) //i != j == k
                    {
                        ans += m[i] * m[j] * (m[j] - 1) / 2;
                        ans %= MOD;
                    }
                    if (target - i - j > j && target - i - j < 101) // All different
                    {
                        ans += m[i] * m[j] * m[target - i - j];
                        ans %= MOD;
                    }
                }
            }
            return ans;
        }

        else if (choose == 3)
        {
            // Initializing as long saves us the trouble of
            // managing count[x] * count[y] * count[z] overflowing later.
            long long count[101] = {}, ans = 0;
            int uniq = 0;
            for (int x : A)
            {
                ++count[x];
                if (count[x] == 1)
                    ++uniq;
            }

            int keys[uniq] = {};
            for (int i = 0, t = 0; i <= 100; ++i)
                if (count[i])
                    keys[t++] = i;

            // Now, let's do a 3sum on "keys", for i <= j <= k.
            // We will use count to add the correct contribution to ans.

            for (int i = 0; i < uniq; ++i)
            {
                int x = keys[i];
                int T = target - x;
                int j = i, k = uniq - 1;
                while (j <= k)
                {
                    int y = keys[j], z = keys[k];
                    if (y + z < T)
                        ++j;
                    else if (y + z > T)
                        --k;
                    else
                    { // # x+y+z == T, now calc the size of the contribution
                        if (i < j && j < k)
                            ans += count[x] * count[y] * count[z];
                        else if (i == j && j < k)
                            ans += count[x] * (count[x] - 1) / 2 * count[z];
                        else if (i < j && j == k)
                            ans += count[x] * count[y] * (count[y] - 1) / 2;
                        else // i == j == k
                            ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;

                        ans %= MOD;
                        ++j;
                        --k;
                    }
                }
            }
            return ans;
        }

        else if (choose == 4)
        {
            unordered_map<int, long long> sums;
            long long ans = 0;
            for (int i = 0; i < A.size(); ++i)
            {
                ans = (ans + sums[target - A[i]]) % MOD;
                for (int j = 0; j < i; ++j)
                    ++sums[A[i] + A[j]];
            }
            return ans;
        }
    }
};