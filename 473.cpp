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
    ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(0);              // untie cin & cout
    cout.tie(0);
    return 0;
}();

class Solution
{
  public:
    bool makesquare(vector<int> &nums)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (nums.size() < 4)
                return false;
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 4)
                return false;
            sum /= 4;
            sort(nums.begin(), nums.end(), greater<int>());
            return helper(nums, 0, sum) && helper(nums, 0, sum) && helper(nums, 0, sum) && helper(nums, 0, sum);
        }

        else if (choose == 1)
        {
            if (nums.size() < 4)
                return false;
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 4)
                return false;

            vector<int> sides(4, 0);
            // Optimize: Sort the match in descending order
            sort(nums.begin(), nums.end(), greater<int>());
            return backtracking(nums, sides, 0, sum / 4);
        }
    }

  private:
    bool backtracking(vector<int> &nums, vector<int> &sides, int start, int target)
    {
        if (start == nums.size())
        {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        // Try adding the current match to each side
        for (int i = 0; i < 4; ++i)
            if (sides[i] + nums[start] <= target)
            {
                // Prune same state occurred before
                int j = 0;
                while (j < i && sides[j] != sides[i])
                    ++j;

                if (j >= i)
                {
                    sides[i] += nums[start]; // add this match to sides[i]
                    if (backtracking(nums, sides, start + 1, target))
                        return true;
                    sides[i] -= nums[start]; // not add this match to sides[i]
                }
            }

        return false;
    }

    bool helper(vector<int> &nums, int start, int target)
    {
        if (!target)
            return true;
        if (target < 0)
            return false;
        for (int i = start; i < nums.size(); ++i)
            if (nums[i])
            {
                int t = nums[i];
                nums[i] = 0;
                if (helper(nums, i + 1, target - t))
                    return true;
                nums[i] = t;
            }
        return false;
    }
};