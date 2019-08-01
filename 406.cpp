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
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		sort(people.begin(), people.end(), [](const vector<int >& a, const vector<int >& b) {
			return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];
			});
		vector<vector<int>> ans;
		for (const vector<int>& p : people)
			ans.emplace(ans.begin() + p[1], p);
		return ans;
	}
};