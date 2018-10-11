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

/*class NumMatrix
{
    vector<vector<int>> dp;

  public:
    NumMatrix(vector<vector<int>> m)
    {
        dp = m;
        for (int i = 0; i < m.size(); ++i)
            for (int j = 1; j < m[0].size(); ++j)
                dp[i][j] += dp[i][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = 0;
        while (row1 <= row2)
        {
            ans += dp[row1][col2] - dp[row1][col1 - 1];
            ++row1;
        }
        return ans;
    }
};*/

class NumMatrix
{
  private:
    vector<vector<int>> dp;

  public:
    NumMatrix(vector<vector<int>> m)
    {
        if (m.empty() || m[0].empty())
            return;
        dp = vector<vector<int>>(m.size() + 1, vector<int>(m[0].size() + 1, 0));
        for (int i = 1; i <= m.size(); ++i)
            for (int j = 1; j <= m[0].size(); ++j)
                dp[i][j] = m[i - 1][j - 1] +
                           dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */