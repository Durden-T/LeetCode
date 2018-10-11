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
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        fill_n(dp, amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (int j = 0; j < coins.size(); ++j)
                if (coins[j] <= i && dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
        return dp[amount] > amount ? -1 : dp[amount];
    }
};