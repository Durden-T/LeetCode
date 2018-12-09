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
#include <ctime>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> M;
        for (int i = 0; i < order.size(); ++i)
            M[order[i]] = i;
        auto cmp = [&M](const string &a, const string &b) {
            for (int i = 0; i < a.size() && i < b.size(); ++i)
                if (M[a[i]] != M[b[i]])
                    return M[a[i]] < M[b[i]];
            return a.size() < b.size();
        };
        return is_sorted(words.begin(), words.end(), cmp);
    }
};