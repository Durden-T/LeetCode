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
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int center = start + (end - start) >> 1;
            if (nums[center] < target)
                start = center + 1;
            else if (nums[center] > target)
                end = center - 1;
            else
                return center;
        }
        return -1;
    }
};