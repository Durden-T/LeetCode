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
    string longestPalindrome(string s)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (s.size() < 2)
                return s;
            bool dp[s.size()][s.size()] = {};
            int max = 1, start = 0;
            for (int i = 0; i < s.size(); ++i)
                for (int j = 0; j <= i; ++j)
                    if ((dp[j][i] = s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) && max < i - j + 1)
                    {
                        max = i - j + 1;
                        start = j;
                    }
            return s.substr(start, max);
        }

        else if (choose == 1)
        {
            if (s.size() < 2)
                return s;
            int start = 0, ans = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                int len = max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i + 1));
                if (len > ans)
                {
                    start = i - (len - 1) / 2;
                    ans = len;
                }
            }
            return s.substr(start, ans);
        }
    }

  private:
    int expandAroundCenter(string &s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};
