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
    double findMaxAverage(vector<int> &nums, int k)
    {
        int cur = 0, sum;
        for (int i = 0; i < k; ++i)
            cur += nums[i];
        sum = cur;
        for (int i = k; i < nums.size(); ++i)
        {
            cur += nums[i] - nums[i - k];
            sum = max(sum, cur);
        }
        return (double)sum / k;
    }
};