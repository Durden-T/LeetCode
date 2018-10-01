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
    vector<string> uncommonFromSentences(string A, string B)
    {
        istringstream sa(A), sb(B);
        unordered_map<string, int> m;
        string t;
        while (sa >> t)
            ++m[t];
        while (sb >> t)
            ++m[t];
        vector<string> ans;
        for (auto &p : m)
            if (p.second == 1)
                ans.push_back(p.first);
        return ans;
    }
};