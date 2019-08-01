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

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	enum STATE { EMPTY = 0, FRESH = 1, ROTTEN = 2 };
	const vector<pair<int, int>> DIRECTIONS{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	int orangesRotting(vector<vector<int>>& grid)
	{
		int nrows = grid.size(), ncols = grid[0].size();
		queue<pair<int, int>> q;
		int numFreshOranges = 0;
		for (int i = 0; i < nrows; ++i)
			for (int j = 0; j < ncols; ++j)
			{
				if (grid[i][j] == ROTTEN)
					q.emplace(i, j);
				if (grid[i][j] == FRESH)
					++numFreshOranges;
			}

		int minute = -1;
		while (!q.empty())
		{
			int qsize = q.size();
			while (qsize--)
			{
				auto top = q.front();
				q.pop();
				int x = top.first, y = top.second;
				for (auto dir : DIRECTIONS)
				{
					int newx = x + dir.first;
					int newy = y + dir.second;
					if (newx < 0 || newy < 0 || newx >= nrows || newy >= ncols || grid[newx][newy] != FRESH) continue;
					grid[newx][newy] = ROTTEN;
					--numFreshOranges;
					q.emplace(newx, newy);
				}
			}
			++minute;
		}
		if (numFreshOranges > 0)
			return -1;

		return (minute == -1) ? 0 : minute;
	}
};


/*class Solution
{
public:
	int orangesRotting(vector<vector<int>>& g)
	{
		bool allFresh = true;
		queue<pair<int, int>> fresh;
		vector<pair<int, int>> change;
		for (int i = 0; i < g.size(); ++i)
			for (int j = 0; j < g[0].size(); ++j)
			{
				if (g[i][j] == 1)
				{
					if ((!i || g[i - 1][j] == 0) && (i == g.size() - 1 || g[i + 1][j] == 0) && (!j || g[i][j - 1] == 0) && (j == g[0].size() - 1 || g[i][j + 1] == 0))
						return -1;
					fresh.emplace(i, j);
				}
				else if (allFresh && g[i][j] == 2)
					allFresh = false;
			}
		if (allFresh)
			return -1;

		int ans = 0, last = 0;
		while (!fresh.empty())
		{
			int n = fresh.size();
			if (n == last)
				return -1;
			last = n;
			while (n--)
			{
				auto& p = fresh.front();
				fresh.pop();
				int i = p.first, j = p.second;
				if (i && g[i - 1][j] == 2 || i < g.size() - 1 && g[i + 1][j] == 2 || j && g[i][j - 1] == 2 || j < g[0].size() - 1 && g[i][j + 1] == 2)
					change.emplace_back(i, j);
				else
					fresh.push(p);
			}

			for (auto& p : change)
				g[p.first][p.second] = 2;
			change.clear();
			++ans;
		}
		return ans;
	}
};
*/
