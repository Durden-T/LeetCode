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
#include<cmath>

using namespace std;

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	vector<int> powerfulIntegers(int x, int y, int bound)
	{
		unordered_set<int> ans;
		double t = log(bound);
		int iLimit = (x != 1 ? t / log(x) : 0), jLimit = (y != 1 ? t / log(y) : 0);
		cout << iLimit << endl << jLimit;
		for (int i = 0; i <= iLimit; ++i)
			for (int j = 0; j <= jLimit; ++j)
				if ((t = pow(x, i) + pow(y, j)) <= bound)
					ans.insert(t);
				else
					break;
		return { ans.begin(), ans.end() };
	}
};
