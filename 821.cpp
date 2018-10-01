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
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> ans(S.size(), S.size());
        int pos = -S.size();
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == C)
                pos = i;
            ans[i] = i - pos;
        }
        for (int i = S.size() - 1; i >= 0; --i)
        {
            if (S[i] == C)
                pos = i;
            ans[i] = min(ans[i], abs(i - pos));
        }
        return ans;


        vector<int> ans(S.size(), INT_MAX);
        int i = 0;

        for (int i = 0; i < S.size(); ++i)
            if (S[i] == C)
            {
                ans[i] = 0;
                for (int j = i - 1; j >= 0 && S[j] != C; --j)
                    ans[j] = i - j;
            }

        for (int i = S.size() - 1; i >= 0; --i)
            if (S[i] == C)
                for (int j = i + 1; j < S.size() && S[j] != C; ++j)
                    ans[j] = min(ans[j], j - i);

        return ans;
    }
};
