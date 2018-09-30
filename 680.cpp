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
    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j])
        {
            ++i;
            --j;
        }
        if (i >= j)
            return true;
        int ti = i + 1, tj = j;
        while (ti < tj && s[ti] == s[tj])
        {
            ++ti;
            --tj;
        }
        if (ti >= tj)
            return true;
        ti = i, tj = j - 1;
        while (ti < tj && s[ti] == s[tj])
        {
            ++ti;
            --tj;
        }
        if (ti >= tj)
            return true;
        return false;
    }
};