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
    int longestPalindrome(string s)
    {
        unordered_map<char, int> map;
        int ans = 0;
        for (char c : s)
            ++map[c];
        for (auto &i : map)
            ans += i.second & 1 && ans & 1 ? i.second - 1 : i.second;
        return ans;
    }
};