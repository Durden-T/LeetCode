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
    string removeKdigits(string num, int k)
    {
        string ans;
        int keep = num.size() - k;
        for (char c : num)
        {
            while (!ans.empty() && ans.back() > c && k)
            {
                ans.pop_back();
                --k;
            }
            if (!ans.empty() || c != '0')
                ans.push_back(c);
        }
        if (!keep || ans.empty())
            return "0";
        return ans.substr(0, keep);
    }
};