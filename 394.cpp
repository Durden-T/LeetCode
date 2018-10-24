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
    string decodeString(string s)
    {
        int choose = 0;
        if (choose == 0)
        {
            stack<string> stk;
            stack<int> nums;
            int num = 0;
            string ans;
            for (char c : s)
            {
                if (isdigit(c))
                    num = num * 10 + c - '0';
                else if (c == '[')
                {
                    stk.push(ans);
                    nums.push(num);
                    ans.clear();
                    num = 0;
                }
                else if (isalpha(c))
                    ans += c;
                else
                {
                    string t = ans;
                    int n = nums.top();
                    while (--n)
                        ans += t;
                    ans = stk.top() + ans;
                    stk.pop();
                    nums.pop();
                }
            }
            return ans;
        }

        
        else if (choose == 1)
        {
            int i = 0;
            return decodeString(s, i);
        }
        }

  private:
    string decodeString(const string &s, int &i)
    {
        string ans;

        while (i < s.length() && s[i] != ']')
        {
            if (!isdigit(s[i]))
                ans += s[i++];
            else
            {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                string t = decodeString(s, ++i);
                i++;

                while (n--)
                    ans += t;
            }
        }
        return ans;
    }
};