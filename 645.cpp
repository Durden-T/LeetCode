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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int choose = 0;
        if (choose == 0)
        {
            unordered_map<int, int> m;
            vector<int> ans(2, 0);
            for (int i : nums)
                ++m[i];
            for (auto &p : m)
                if (!ans[0] && p.second == 2)
                    ans[0] = p.first;
            for (int i = 1; i <= nums.size(); ++i)
                if (!m.count(i))
                    ans[1] = i;
            return ans;
        }
        else if (choose == 1)
        {
            sort(nums.begin(), nums.end());
            int dup = 0, missing = nums[0] != 1;
            for (int i = 1; i < nums.size(); ++i)
            {
                if (dup && missing)
                    return {dup, missing};
                if (nums[i] == nums[i - 1])
                    dup = nums[i];
                else if (nums[i] > nums[i - 1] + 1)
                    missing = nums[i - 1] + 1;
            }
            return {dup, (nums.back() != nums.size()) ? (int)nums.size() : missing};
        }
        else if (choose == 2)
        {
            int total = 0, xor0 = 0, xor1 = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                total ^= i + 1;
                total ^= nums[i];
            }
            int rightmostbit = total & ~(total - 1);
            for (int n : nums)
            {
                if (n & rightmostbit)
                    xor1 ^= n;
                else
                    xor0 ^= n;
            }
            for (int i = 1; i <= nums.size(); ++i)
            {
                if (i & rightmostbit)
                    xor1 ^= i;
                else
                    xor0 ^= i;
            }
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == xor0)
                    return {xor0, xor1};
            }
            return {xor1, xor0};
        }
    }
};