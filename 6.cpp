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

static int __initialSetup = []() {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    string convert(string s, int nRows)
    {
        if (nRows <= 1)
            return s;
        vector<string> str(nRows);
        for (int i = 0, row = 0, step = 1; i < s.size(); ++i)
        {
            str[row] += s[i];
            if (!row)
                step = 1;
            else if (row == nRows - 1)
                step = -1;
            row += step;
        }
        s.clear();
        for (int i = 0; i < nRows; ++i)
            s += str[i];
        return s;
    }
};