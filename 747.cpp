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
    int dominantIndex(vector<int> &nums)
    {
        int max = -1, maxi;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > max)
            {
                max = nums[i];
                maxi = i;
            }
        for (int i : nums)
            if (i != max && 2 * i > max)
                return -1;
        return maxi;
    }
};