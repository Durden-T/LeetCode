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
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < (int)S.size() - 2; ++i)
        {
            int j = i;
            while (j < S.size() && S[j] == S[i])
                ++j;
            if (j-- - i > 2)
                ans.push_back({i, j});
            i = j;
        }
        return ans;
    }
};
