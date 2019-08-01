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
	int largestSumAfterKNegations(vector<int>& A, int K)
	{
		int choose = 0;
		if (choose == 0)
		{
			int sum = accumulate(A.begin(), A.end(), 0);
			priority_queue<int, vector<int>, greater<int>> PQ(A.begin(), A.end(), greater<int>());
			while (K--)
			{
				int t = PQ.top();
				PQ.pop();
				PQ.push(-t);
				sum -= 2 * t;
			}

			return sum;
		}
		else if (choose == 1)
		{
			sort(A.begin(), A.end());
			int sum = 0, i = 0;
			for (int i = 0; K-- > 0 && A[i]; ++i)
			{
				A[i] = -A[i];
				if (i + 1 < A.size() && A[i] > A[i + 1])
					continue;
				else
				{
					if (K & 1)
						A[i] = -A[i];
					break;
				}
			}

			return accumulate(A.begin(), A.end(), 0);
		}
		else if (choose == 2)
		{
			sort(A.begin(), A.end());
			for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K)
				A[i] = -A[i];
			return accumulate(A.begin(), A.end(), 0) - (K % 2) * *min_element(A.begin(), A.end()) * 2;
		}
		return 0;
	}
};