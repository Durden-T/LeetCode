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
	vector<int> addToArrayForm(vector<int>& a, int k)
	{
		int i = a.size() - 1;
		while (k && i >= 0)
		{
			a[i] += k % 10;
			k /= 10;
			k += a[i] / 10;
			a[i] %= 10;
			--i;
		}
		while (k)
		{
			a.insert(a.begin(), k % 10);
			k /= 10;
		}
		return a;
	}
};
};