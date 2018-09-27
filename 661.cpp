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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int R = M.size(), C = M[0].size();
        vector<vector<int>> ans(R, vector<int>(C));
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
            {
                int count = 0;
                for (int nr = r - 1; nr <= r + 1; ++nr)
                    for (int nc = c - 1; nc <= c + 1; ++nc)
                    {
                        if (0 <= nr && nr < R && 0 <= nc && nc < C)
                        {
                            ans[r][c] += M[nr][nc];
                            ++count;
                        }
                    }
                ans[r][c] /= count;
            }
        return ans;
    }
};