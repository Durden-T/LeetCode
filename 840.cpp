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
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i < grid.size() - 2; ++i)
            for (int j = 0; j < grid[0].size() - 2; ++j)
                ans += grid[i + 1][j + 1] == 5 && helper(grid, i, j);
        return ans;
    }

  private:
    bool helper(vector<vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 5) //check there are duplicates or not
            return false;
        for (int i = r; i < r + 3; ++i)
            for (int j = c; j < c + 3; ++j)
                if (grid[i][j] > 9)
                    return false;

        return grid[r][c] + grid[r][c + 1] + grid[r][c + 2] == 15 &&
               grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] == 15 &&
               grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] == 15 &&
               grid[r][c] + grid[r + 1][c] + grid[r + 2][c] == 15 &&
               grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] == 15 &&
               grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] == 15 &&
               grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == 15 &&
               grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] == 15;
    }
};