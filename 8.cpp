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
    int myAtoi(string str)
    {
        if (str.empty())
            return 0;
        bool negative = false;
        int i = 0;
        long long ans = 0;
        while (str[i] == ' ')
            ++i;
        if (str[i] == '-')
            negative = true;
        else if (isdigit(str[i]))
            ans = str[i] - '0';
        else if (str[i] != '+')
            return 0;
        ++i;
        while (i < str.size() && (isdigit(str[i])))
        {
            ans = 10 * ans + str[i++] - '0';
            if (ans > INT_MAX)
                return negative ? INT_MIN : INT_MAX;
        }
        return negative ? -ans : ans;
    }
};