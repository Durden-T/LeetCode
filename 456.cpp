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
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;
        int largest = INT_MIN;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it)
        {
            if (*it < largest)
                return true;
            while (!s.empty() && s.top() < *it)
            {
                largest = s.top();
                s.pop();
            }
            s.push(*it);
        }
        return false;
    }
};


/*class Solution
{
  public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int min_i = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            min_i = min(min_i, nums[i]);
            for (int j = i + 1, max_j = INT_MIN; j < nums.size(); ++j)
            {
                if (nums[j] > min_i && nums[j] < max_j)
                    return true;
                max_j = max(max_j, nums[j]);
            }
        }
        return false;
    }
};

class Solution
{
  public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        int min_i = INT_MAX;
        for (int j = 0; j < nums.size() - 1; ++j)
        {
            min_i = min(min_i, nums[j]);
            for (int k = j + 1; k < nums.size(); ++k)
                if (nums[k] < nums[j] && min_i < nums[k])
                    return true;
        }
        return false;
    }
};*/