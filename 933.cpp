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

class RecentCounter
{
public:
	RecentCounter()
	{
	}

	int ping(int t)
	{
		res.push_back(t);
		i = lower_bound(i, res.size() - 1, t - 3000);
		return res.size() - i;
	}
private:
	int lower_bound(int start, int end,int val)
	{
		while (start <= end)
		{
			int center = start + (end - start) / 2;
			if (res[center] < val)
				start = center + 1;
			else
				end = center - 1;
		}
		return start;

	}
	
	vector<int> res;
	int i = 0;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
