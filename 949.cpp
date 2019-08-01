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
	string largestTimeFromDigits(vector<int>& A)
	{
		sort(A.begin(), A.end());
		char buf[6];
		string ans;
		do
		{
			if (10 * A[0] + A[1] < 24&&10 * A[2] + A[3] < 60)
				sprintf(buf, "%02d:%02d", 10 * A[0] + A[1],10 * A[2] + A[3]);
            else
                continue;
			ans = max(ans, string(buf));
		} while (next_permutation(A.begin(), A.end()));
		return ans;
	}
};