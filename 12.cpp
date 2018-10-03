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

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int diff = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if (sum < target)
                    ++j;
                else if (sum > target)
                    --k;
                else
                    return target;
            }
        }
        return ans;
    }
};