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
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int count = 1, cur = 0;
        for (int c : S)
            if ((cur += widths[c - 'a']) > 100)
            {
                ++count;
                cur = widths[c - 'a'];
            }
        return {count, cur};
    }
};