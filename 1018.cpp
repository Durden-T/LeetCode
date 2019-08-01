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
	vector<bool> prefixesDivBy5(vector<int>& A)
	{
		vector<bool> ans(A.size());
		int last = 0;
		for (int i = 0; i < A.size(); ++i)
			ans[i] = ((last = (2 * last + A[i]) % 5) == 0);
		return ans;
	}
};