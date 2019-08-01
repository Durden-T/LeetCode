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
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
	{
		vector<vector<int>> ans;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				ans.push_back({ i, j });
		sort(ans.begin(), ans.end(), [r0, c0](const vector<int>& a, const vector<int>& b) {
			return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
			});
		return ans;
	}
};