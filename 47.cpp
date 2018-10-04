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
    vector<vector<int>> ans;
    unordered_set<int> s;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return ans;
        helper(nums, 0);
        return ans;
    }

  private:
    void helper(vector<int> &nums, int pos)
    {
        if (pos == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); ++i)
            if (!s.count(i))
            {
                s.insert(i);
                swap(nums[pos], nums[i]);
                helper(nums, pos + 1);
                swap(nums[pos], nums[i]);
            }
    }
};

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    vector<vector<int>> ans;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return ans;
        helper(nums, 0);
        return ans;
    }

  private:
    void helper(vector<int> &nums, int pos)
    {
        if (pos == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); ++i)
        {
            if(i!=pos&&nums[i]==nums[pos])
                continue;
            swap(nums[pos], nums[i]);
            helper(nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};