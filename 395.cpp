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
    int longestSubstring(string s, int k)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (s.empty() || k > s.size())
                return 0;
            if (k == 0)
                return s.size();

            unordered_map<char, int> Map;
            for (int i = 0; i < s.size(); ++i)
                ++Map[s[i]];

            int idx = 0;
            while (idx < s.size() && Map[s[idx]] >= k)
                ++idx;
            if (idx == s.size())
                return s.size();

            int left = longestSubstring(s.substr(0, idx), k);
            int right = longestSubstring(s.substr(idx + 1), k);

            return max(left, right);
        }
        else if (choose == 1)
        {
            int n = s.size();
            return helper(s, 0, n - 1, k);
        }
    }

  private:
    // looking for longest string within index range [l, r]
    int helper(string &s, int l, int r, int k)
    {
        vector<int> mp(26, 0);
        for (int i = l; i <= r; ++i)
            ++mp[s[i] - 'a'];
        // check whether the whole string meets requirement
        bool pass = true;
        for (int i = 0; i < 26 && pass; ++i)
            if (mp[i] && mp[i] < k)
                pass = false;
        if (pass)
            return r - l + 1;
        // using all characters with occurrence > 0 && < k to divide the string
        int i = l, ans = 0;
        for (int j = l; j <= r; ++j)
        {
            if (mp[s[j] - 'a'] && mp[s[j] - 'a'] < k)
            {
                ans = max(ans, helper(s, i, j - 1, k));
                i = j + 1;
            }
        }
        return max(ans, helper(s, i, r, k));
    }
};