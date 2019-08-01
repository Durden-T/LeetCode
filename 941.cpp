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
	bool validMountainArray(vector<int>& A)
	{
		if (A.size() < 3 || A[0] > A[1])
			return false;
		auto t = is_sorted_until(A.begin(), A.end());
		if (t == A.end())
			return false;
		while (t != A.end() - 1)
			if (*t <= *++t)
				return false;
		return true;
	}
};