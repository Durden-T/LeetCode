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