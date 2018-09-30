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
    int countBinarySubstrings(string s)
    {
        int choose = 1;
        if (choose == 0)
        {
            int ans = 0, count0 = 0, count1 = 0;
            if (s[0] == '0')
                ++count0;
            else
                ++count1;
            for (int i = 1; i < s.size(); ++i)
                if (s[i] == '0')
                {
                    ++count0;
                    if (s[i - 1] == '1')
                        count0 = 1;
                    if (count0 <= count1)
                        ++ans;
                }
                else if (s[i] == '1')
                {
                    ++count1;
                    if (s[i - 1] == '0')
                        count1 = 1;
                    if (count1 <= count0)
                        ++ans;
                }
            return ans;
        }
        else if (choose == 1)
        {
            int ans = 0, start = 0, end = 0, pre = 0, cur = 0;
            while (start < s.size())
            {
                while (end + 1 < s.size() && s[end + 1] == s[start])
                    ++end;
                int cur = end - start + 1;
                ans += min(cur, pre);
                pre = cur;
                start = end + 1;
                end = start;
            }
            return ans;
        }
    }
};