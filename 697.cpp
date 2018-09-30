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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int findShortestSubArray(vector<int> &nums)
    {
        int count[50000] = {0};
        vector<pair<int, int>> map(50000, {-1, -1});
        int maxcount = 0, ans;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!count[nums[i]])
                map[nums[i]].first = i;
            ++count[nums[i]];
            map[nums[i]].second = i - map[nums[i]].first + 1;
            if (count[nums[i]] > maxcount)
            {
                maxcount = count[nums[i]];
                ans = map[nums[i]].second;
            }
            else if (count[nums[i]] == maxcount)
                ans = min(ans, map[nums[i]].second);
        }

        return ans;
    }
};