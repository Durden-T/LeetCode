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
	int twoCitySchedCost(vector<vector<int>>& costs)
	{
		int choose = 1;
		if (choose == 0)
		{
			int ans = 0;
			sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
				return abs(a[0] - a[1]) > abs(b[0] - b[1]);
				});
			int a, b;
			a = b = costs.size() / 2;
			int i = 0;
			for (; a && b; ++i)
				if (costs[i][0] < costs[i][1])
				{
					ans += costs[i][0];
					--a;
				}
				else
				{
					ans += costs[i][1];
					--b;
				}
			while (a--)
				ans += costs[i++][0];
			while (b--)
				ans += costs[i++][1];
			return ans;
		}
		else if (choose == 1)
		{
			sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
				return a[0] - a[1] < b[0] - b[1];
				});
			int ans = 0;
			for (int i = 0; i < costs.size() / 2; ++i)
				ans += costs[i][0] + costs[costs.size() - i - 1][1];
			return ans;
		}
        return 0;
	}
};