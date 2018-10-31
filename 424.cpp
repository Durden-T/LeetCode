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
    int characterReplacement(string s, int k)
    {
        int count[26] = {};
        int start = 0, curMaxCount = 0, ans = 0;
        for (int end = 0; end < s.size(); ++end)
        {
            curMaxCount = max(curMaxCount, ++count[s[end] - 'A']);
            while (end - start + 1 - curMaxCount > k)
                --count[s[start++] - 'A'];
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};