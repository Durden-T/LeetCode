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

static int __initialSetup = []
{
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	vector<int> watch = { 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
	vector<string> readBinaryWatch(int num)
	{
		int choose = 0;
		if (choose == 0)
		{
			vector<string> ans;
			helper(num, 0, 0, 0, ans);
			return ans;
		}
		else if (choose == 1)
		{
			vector<string> rs;
			for (int h = 0; h < 12; h++)
				for (int m = 0; m < 60; m++)
					if (bitset<10>(h << 6 | m).count() == num)
						rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
			return rs;
		}
		

	}
	void helper(int num, int i, int hour, int minute, vector<string>& ans)
	{
		if (!num)
		{
			string t = to_string(minute);
			ans.emplace_back(to_string(hour) + ':' + (minute < 10 ? '0' + t : t));
			return;
		}
		if (i >= 10)
			return;
		helper(num, i + 1, hour, minute, ans);
		if (i < 4 && hour + watch[i] < 12)
			helper(num - 1, i + 1, hour + watch[i], minute, ans);
		else if (i > 3 && minute + watch[i] < 60)
			helper(num - 1, i + 1, hour, minute + watch[i], ans);
	}
};