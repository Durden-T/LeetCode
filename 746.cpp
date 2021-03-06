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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp[cost.size() + 1]={0,0};
        for (int i = 2; i <= cost.size(); ++i)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 1]);
        return dp[cost.size()];
    }
};