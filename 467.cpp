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
    int findSubstringInWraproundString(string p)
    {
        int count[26] = {0};
        int cnt = 1;
        for (int i = 0; i < p.size(); ++i)
        {
            if (i > 0 && (p[i] - p[i - 1] == 1 || (p[i - 1] - p[i] == 25)))
                ++cnt;
            else
                cnt = 1;

            count[p[i] - 'a'] = max(count[p[i] - 'a'], cnt);
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};