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
	int findJudge(int N, vector<vector<int>>& trust) 
	{
		vector<int> count(N + 1, 0);
		for (auto& t : trust)
		{
			--count[t[0]];
			++count[t[1]];
		}
		for (int i = 1; i <= N; ++i)
			if (count[i] == N - 1) 
				return i;
		return -1;
	}
};
