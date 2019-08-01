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
	bool divisorGame(int N)
	{
		int choose = 0;
		if (choose == 0)
		{
			return !(N & 1);
		}
		else if (choose == 1)
		{
			if (N == 1)
				return false;
			vector<bool> dp(N + 1, false);
			dp[2] = 1;
			for (int i = 3; i <= N; ++i)
				for (int j = 1; j < i && !dp[i]; ++j)
					if (i % j == 0)
						dp[i] = !dp[i - j];
			return dp[N];
		}
        return 0;
	}
};