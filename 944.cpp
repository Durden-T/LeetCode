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
	int minDeletionSize(vector<string>& A)
	{
        if(A.size() < 2)
            return 0;
		int n = A[0].size(), count = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 1; j < A.size(); ++j)
				if (A[j][i] < A[j - 1][i])
				{
					++count;
					break;
				}
		return count;
	}
};