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
    int surfaceArea(vector<vector<int>> &grid)
    {

        int xCommon = 0; // common surfaces in x dimension
        int yCommon = 0; // common surfaces in y dimension
        int zCommon = 0; // common surfaces in z dimension
        int Cubes = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (c > 0)
                    xCommon += min(grid[r][c - 1], grid[r][c]);

                if (r > 0)
                    yCommon += min(grid[r - 1][c], grid[r][c]);

                zCommon += max(grid[r][c] - 1, 0);

                Cubes += grid[r][c];
            }
        }

        int exposedSurfaceArea = (Cubes * 6) - (xCommon * 2) - (yCommon * 2) - (zCommon * 2);

        return exposedSurfaceArea;
    }
};