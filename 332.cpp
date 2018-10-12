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
    multimap<string, string> m;
    vector<string> ans;
    multimap<string, string>::iterator it;

  public:
    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        sort(tickets.begin(), tickets.end());
        for (auto &p : tickets)
            m.insert(p);
        vector<string> t = {"JFK"};
        helper(t, tickets.size() + 1);
        return ans;
    }
    void helper(vector<string> &t, int size)
    {
        while (ans.empty() && (it = m.find(t.back())) != m.end())
        {
            t.push_back(it->second);
            m.erase(it);
            auto p = *it;
            helper(t,size);
            t.pop_back();
            m.insert(p);
        }
        if (t.size() == size)
            ans = t;
    }
};