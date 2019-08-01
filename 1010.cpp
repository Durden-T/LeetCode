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
	int numPairsDivisibleBy60(vector<int>& time)
	{
		int ans = 0;
		int table[60] = { 0 };
		for (int i : time)
		{
			ans += table[(60 - i % 60) % 60];
			++table[i % 60];
		}
		return ans;

		/*
		int table[60] = { 0 };
		for (int i : time)
			++table[i % 60];
		int ans = (table[0] * (table[0] - 1) + table[30] * (table[30] - 1)) / 2;
		for (int i = 1; i < 30; ++i)
			ans += table[i] * table[60 - i];
		return ans;
		*/
	}
};