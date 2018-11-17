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
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (desiredTotal <= maxChoosableInteger)
            return true;
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) >> 1;
        if (desiredTotal > sum)
            return false;
        if (desiredTotal == sum)
            return maxChoosableInteger % 2;
        vector<char> dp(1 << maxChoosableInteger, 0);
        return helper(dp, desiredTotal, 0, maxChoosableInteger);
    }

  private:
    bool helper(vector<char> &dp, int desiredTotal, int used, int maxChoosableInteger)
    {
        if (dp[used])
            return dp[used] == 'w';
        for (int i = 0; i < maxChoosableInteger; ++i)
        {
            if (!(used & 1 << i) && (i + 1 >= desiredTotal || !helper(dp, desiredTotal - i - 1, used | 1 << i, maxChoosableInteger)))
                return dp[used] = 'w';
        }
        return !(dp[used] = 'l');
    }
};

/*class Solution
{
  public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (((maxChoosableInteger + 1) * maxChoosableInteger) / 2 < desiredTotal)
            return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }

    bool canWin(int length, int total, int used, unordered_map<int, bool> &m)
    {
        if (m.count(used))
            return m[used];
        for (int i = 0; i < length; ++i)
        {
            int cur = (1 << i);
            if ((cur & used) == 0)
            {
                if (total <= i + 1 || !canWin(length, total - (i + 1), used | cur, m))
                { // used | cur failed
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};

class Solution
{

  public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        vector<bool> table(maxChoosableInteger + 1, false);
        return helper(desiredTotal, table);
    }

  private:
    bool helper(int desiredTotal, vector<bool> &table)
    {
        for (int i = 1; i < table.size(); ++i)
            if (!table[i])
            {
                if (desiredTotal - i <= 0)
                    return true;
                table[i] = true;
                if (!helper(desiredTotal - i, table))
                {
                    table[i] = false;
                    return true;
                }
                table[i] = false;
            }
        return false;
    }
};*/