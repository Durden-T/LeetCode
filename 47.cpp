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
	void recursion(vector<int> num, int i, int j, vector<vector<int> >& res)
	{
		if (i == j - 1) {
			res.push_back(num);
			return;
		}
		for (int k = i; k < j; k++) {
			if (i != k && num[i] == num[k]) continue;
			swap(num[i], num[k]);
			recursion(num, i + 1, j, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int>& num)
	{
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		recursion(num, 0, num.size(), res);
		return res;
	}
};