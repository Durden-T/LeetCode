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
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> M;
        vector<string> ans;
        for (string &s : cpdomains)
        {
            int i = 0;
            while (i < s.size() && isdigit(s[i]))
                ++i;
            int count = stoi(s.substr(0, i));
            ++i;
            M[s.substr(i)] += count;
            while (i < s.size())
                if (s[i++] == '.')
                    M[s.substr(i)] += count;
        }
        for (auto &p : M)
            ans.emplace_back(to_string(p.second) + ' ' + p.first);
        return ans;
    }
};