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
	vector<string> commonChars(vector<string>& A)
	{
		vector<string> ans;

		vector<vector<int>> table(26, vector<int>(A.size(), 0));

		for (int i = 0; i < A.size(); ++i)
			for (char c : A[i])
				++table[c - 'a'][i];
		for (int i = 0; i < 26; ++i)
		{
			int m = INT_MAX;
			for (int t : table[i])
				m = min(m, t);
			if (m)
			{
				string fuck = string(1, 'a' + i);
				ans.insert(ans.end(), m, fuck);
			}
		}
		return ans;
	}
};
