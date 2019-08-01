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
	bool canThreePartsEqualSum(vector<int>& A)
	{
		int choose = 0;
		if (choose == 0)

		{
			int all = accumulate(A.begin(), A.end(), 0);
			if (all % 3)
				return false;
			int sum = all / 3;
			int i = 0, j = A.size() - 1;
			int left = 0, right = 0;
			while (i < A.size() - 2 && left != sum)
				left += A[i++];
			if (left != sum)
				return false;
			while (j > 1 && right != sum)
				right += A[j--];
			if (right != sum)
				return false;
			return i + 1 < j && accumulate(A.begin() + i, A.begin() + j + 1, 0) == sum;
		}
		else if (choose == 1)
		{
			for (int i = 1; i < A.size(); ++i)
				A[i] += A[i - 1];
			int sum = A[A.size() - 1];
			if (sum % 3 != 0)
				return false;
			sum /= 3;
			int k = 1;
			for (int i = 0; i < A.size(); ++i)
				if (A[i] == sum * k) ++k;
			return k == 4;
		}
		return false;
	}
};