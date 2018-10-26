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
    bool canPartition(vector<int> &nums)
    {
        int choose = 2;
        if (choose == 0)
        {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum & 1)
                return false;
            sort(nums.begin(), nums.end(), greater<int>());
            return helper(nums, 0, sum >> 1);
        }
        else if (choose == 1)
        {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum & 1)
                return false;
            int target = sum >> 1;
            bool dp[target + 1] = {true};
            for (int num : nums)
            {
                if (dp[target])
                    return true;
                for (int i = target; i >= num && !dp[i]; --i)
                    dp[i] |= dp[i - num];
            }
            return dp[target];
        }
        else if (choose == 2) //???
        {
            bitset<5001> bits(1);
            int sum = accumulate(nums.begin(), nums.end(), 0);
            for (auto n : nums)
                bits |= bits << n;
            return !(sum & 1) && bits[sum >> 1];
        }
    }

  private:
    bool helper(vector<int> &nums, int i, int target)
    {
        if (target == nums[i])
            return true;
        if (target < nums[i])
            return false;
        return helper(nums, i + 1, target - nums[i]) || helper(nums, i + 1, target);
    }
};
