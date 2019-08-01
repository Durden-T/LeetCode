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

static int __initialSetup = [] {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words)
	{
		string ans;
		vector<int> table(26, 0);
		for (char c : licensePlate)
			if (isalpha(c))
				++table[tolower(c) - 'a'];
		for (string& s : words)
		{
			bool found = true;
			vector<int> tmp = table;
			for (char c : s)
				--tmp[c - 'a'];
			for (int i = 0; i < 26; ++i)
				if (tmp[i] > 0)
				{
					found = false;
					break;
				}
			if (found && (ans.empty() || s.size() < ans.size()))
				ans = s;
		}
		return ans;
	}
};