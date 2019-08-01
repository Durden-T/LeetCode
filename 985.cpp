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
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
	{
		vector<int> ans(A.size());
		int sum = 0;
		for (int i = 0; i < A.size(); ++i)
			if ((A[i] & 1) == 0)
				sum += A[i];

		for (int i = 0; i < queries.size(); ++i)
		{
			int val = queries[i][0], index = queries[i][1];
			if (!(A[index] & 1))
				sum -= A[index];
			A[index] += val;
			if (!(A[index] & 1))
				sum += A[index];
			ans[i] = sum;
		}
		return ans;
	}
};