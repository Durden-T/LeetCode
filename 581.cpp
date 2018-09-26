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
    int findUnsortedSubarray(vector<int> &nums)
    {
        int choose = 0;
        if (choose == 0)
        {
            vector<int> t(nums);
            sort(t.begin(), t.end());
            int i = 0;
            while (i < nums.size() && nums[i] == t[i])
                ++i;
            int start = i;
            i = nums.size() - 1;
            while (i > start && nums[i] == t[i])
                --i;
            return i - start + 1;
        }

        else if (choose == 1)
        {
            stack<int> s;
            int l = nums.size(), r = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                while (!s.empty() && nums[s.top()] > nums[i])
                {
                    l = min(l, s.top());
                    s.pop();
                }
                s.push(i);
            }
            s = stack<int>();
            for (int i = nums.size() - 1; i >= 0; --i)
            {
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    r = max(r, s.top());
                    s.pop();
                }
                s.push(i);
            }
            return r - l > 0 ? r - l + 1 : 0;
        }
        else if (choose == 2)
        {
            if (nums.empty())
                return 0;

            int i = 0, j = -1;
            int min = INT_MAX, max = INT_MIN;

            for (int l = 0; l < nums.size(); ++l)
                if (nums[l] >= max)
                    max = nums[l];
                else
                    j = l;

            for (int r = nums.size() - 1; r >= 0; --r)
                if (nums[r] <= min)
                    min = nums[r];
                else
                    i = r;

            return j - i + 1;
        }
    }
};