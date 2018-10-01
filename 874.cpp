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
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        set<pair<int, int>> obstacleSet;
        for (vector<int> &obstacle : obstacles)
            obstacleSet.emplace(obstacle[0], obstacle[1]);

        int ans = 0;
        for (int cmd : commands)
        {
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else
                for (int k = 0; k < cmd; ++k)
                {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleSet.find({nx, ny}) == obstacleSet.end())
                    {
                        x = nx;
                        y = ny;
                        ans = max(ans, x * x + y * y);
                    }
                    else
                        break;
                }
        }
        return ans;
    }
};