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
	vector<int> partitionLabels(string S)
	{
		vector<int> ans;
		vector<int> table(26);
		for (int i = 0; i < S.size(); ++i)
			table[S[i] - 'a'] = i;

		for (int i = 0, pos = 0, j = 0; i < S.size(); ++i)
		{
			j = max(j, table[S[i] - 'a']);
			if (i == j)
			{
				ans.push_back(i - pos + 1);
				pos = i + 1;
			}
		}
		return ans;
	}
};