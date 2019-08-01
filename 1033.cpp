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
	vector<int> numMovesStones(int a, int b, int c)
	{
		vector<int> s = { a, b, c };
		sort(s.begin(), s.end());
		if (s[1] == s[2] - 1 && s[0] == s[1] - 1)
			return { 0, 0 };
		return { s[1] - s[0] < 3 || s[2] - s[1] < 3 ? 1 : 2, s[2] - s[0] - 2 };
	}
};

