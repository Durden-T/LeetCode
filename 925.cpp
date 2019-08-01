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
	bool isLongPressedName(string name, string typed)
	{
		if (typed.size() < name.size())
			return false;
		int i = 0;
		for (int j = 0; j < typed.size(); ++j)
			if (i < name.size() && name[i] == typed[j])
				++i;
			else if (!j || typed[j] != typed[j - 1])
				return false;
		return i == name.size();
	}
};