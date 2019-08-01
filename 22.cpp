#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include<vector>
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
	vector<string> generateParenthesis(int n)
	{
		int choose = 0;
		if (choose == 0)
		{
			vector<string> ans;
			string path;
			helper(n, n, path, ans);
			return ans;
		}
		else if (choose == 1)
		{
			vector<string> ans;
			addingpar(ans, "", n, 0);
			return ans;
		}
        return {};
	}
private:
	void helper(int l, int r, string& path, vector<string>& ans)
	{
		if (l > r)
			return;
		if (!l && !r)
		{
			ans.push_back(path);
			return;
		}
		if (l)
		{
			path += '(';
			helper(l - 1, r, path, ans);
			path.pop_back();
		}
		if (r)
		{
			path += ')';
			helper(l, r - 1, path, ans);
			path.pop_back();
		}
	}

	void addingpar(vector<string>& v, string str, int n, int m)
	{
		if (!n && !m)
		{
			v.emplace_back(str);
			return;
		}
		if (m)
			addingpar(v, str + ")", n, m - 1);
		if (n)
			addingpar(v, str + "(", n - 1, m + 1);
	}
};