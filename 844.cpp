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
    bool backspaceCompare(string S, string T)
    {
        stack<char> a, b;
        for (char c : S)
            if (c == '#')
            {
                if (!a.empty())
                    a.pop();
            }
            else
                a.push(c);
        for (char c : T)
            if (c == '#')
            {
                if (!b.empty())
                    b.pop();
            }
            else
                b.push(c);
        return a == b;
    }
};