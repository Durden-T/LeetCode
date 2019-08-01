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

static int __initialSetup = []()
{
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	vector<int> diStringMatch(string S)
	{
		int low = 0, high = S.size();
		vector<int> ans;
		for (char c : S)
			ans.push_back(c == 'I' ? low++ : high--);
		ans.push_back(low);//low == high
		return ans;
	}
};