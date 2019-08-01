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
	int numTrees(int n)
	{
		int dp[n + 1] = { 1, 1 };
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= i / 2; ++j)
				dp[i] += dp[j - 1] * dp[i - j];
			dp[i] <<= 1;
			if (i % 2)
				dp[i] += dp[i / 2] * dp[i / 2];

		}
		return dp[n];
	}
};
