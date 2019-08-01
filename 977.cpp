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
	vector<int> sortedSquares(vector<int>& A)
	{
		int n = A.size(), count = 0;
		if (A.size() == 1)
		{
			A[0] = A[0] * A[0];
			return A;
		}
		int j = distance(A.begin(), lower_bound(A.begin(), A.end(), 0)), i = j - 1;
		vector<int> ans(n);
		while (i >= 0 && j < n)
			if (A[i] * A[i] > A[j] * A[j])
			{
				ans[count++] = A[j] * A[j];
				++j;
			}
			else
			{
				ans[count++] = A[i] * A[i];
				--i;
			}
		while (i >= 0)
		{
			ans[count++] = A[i] * A[i];
			--i;
		}
		while (j < n)
		{
			ans[count++] = A[j] * A[j];
			++j;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector<int> A = { -2, 0 };
	a.sortedSquares(A);

	return 0;
}