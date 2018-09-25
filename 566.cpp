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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (nums.size() * nums[0].size() != r * c)
                return nums;
            vector<vector<int>> ans(r, vector<int>(c));
            int oi = 0, oj = 0;
            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                {
                    ans[i][j] = nums[oi][oj];
                    if (++oj >= nums[0].size())
                    {
                        oj = 0;
                        if (++oi >= nums.size())
                            return ans;
                    }
                }
        }
        else if (choose == 1)
        {
            int h = nums.size(), w = nums[0].size(), size = r * c;
            if (h * w != size)
                return nums;

            vector<vector<int>> ans(r, vector<int>(c));
            for (int i = 0; i < size; ++i)
            {
                int hi = i / w;
                int wi = i - hi * w;
                int ri = i / c;
                int ci = i - ri * c;
                ans[ri][ci] = nums[hi][wi];
            }
            return ans;
        }
    }
};