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
    bool circularArrayLoop(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] % nums.size())
            {
                bool direction = (nums[i] > 0); // loop direction + or -
                int start = i;
                do
                {
                    int next = (i + nums[i]) % nums.size();
                    nums[i] = 0; // mark this index as visited
                    i = next;
                } while (nums[i] % nums.size() && direction == (nums[i] > 0)); // while no self-loop or direction change
                if (i == start)
                    return true;
            }
        return false;
    }
};
/*
class Solution
{
  public:
    bool circularArrayLoop(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i])
            {
                bool direction = (nums[i] > 0);
                int start = i, cur = i, next;

                while ((next = find(nums, cur)) && nums[next] && direction == (nums[next] > 0))
                {
                    nums[cur] = 0;
                    cur = next;
                }
                if (next == start && next != cur)
                    return true;
                else
                    nums[cur] = 0;
            }
        return false;
    }

  private:
    int find(vector<int> &nums, int i)
    {
        return nums[i] > 0 ? (i + nums[i]) % nums.size() : (-2 - nums[i]) % nums.size();
    }
};*/
