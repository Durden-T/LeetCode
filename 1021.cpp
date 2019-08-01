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
	string removeOuterParentheses(string S)
	{
		string ans;
		int count = 0, start = 1;
		for (int i = 0; i < S.size(); ++i)
			if ((count += S[i] == '(' ? 1 : -1) == 0)
			{
				ans += S.substr(start, i - start);
				start = i + 2;
			}
		return ans;
	}
};