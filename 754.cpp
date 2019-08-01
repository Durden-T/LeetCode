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
	int reachNumber(int target)
	{
		target = abs(target);
		int step = 0;
		int sum = 0;
		while (sum < target)
		{
			++step;
			sum += step;
		}
		return (sum - target) & 1 ? step + ((step & 1) ? 2 : 1) : step;
	}
};