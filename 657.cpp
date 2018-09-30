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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    bool judgeCircle(string moves)
    {
        int a = 0, b = 0;
        for(char c:moves)
        {
            if(c=='U')
                ++a;
            else if(c=='D')
                --a;
            else if(c=='A')
                ++b;
            else
                --b;
        }
        return !a && !b;
    }
};