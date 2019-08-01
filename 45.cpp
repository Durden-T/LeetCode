#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include<vector>
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
	int jump(vector<int>& nums)
	{
		int choose = 0;
		if (choose == 0)
		{
			int ans = 0;
			for (int i = 0, last = 0, cur = 0; i < nums.size() - 1; ++i)
			{
				cur = max(cur, i + nums[i]);
				if (i == last)
				{
					++ans;
					last = cur;
				}
			}
			return ans;
		}
		else if (choose == 1)
		{
			// Next level's range is nums[current level's end + 1 .. right most location current level can reach]
			for (size_t levelStart = 0, levelEnd = 0, level = 0, maxEnd = 0;
				levelStart < nums.size();
				levelStart = levelEnd + 1, levelEnd = maxEnd, ++level)
			{
				// Current level covers the last element, means we've reached the destination in current level, so level is the shortest step count.
				if (levelEnd >= nums.size() - 1)
					return level;

				// find the right most location that current level can reach.
				for (size_t i = levelStart; i <= levelEnd; ++i)
					// for element nums[i], its right most reachable location is nums[i] + i
					maxEnd = max(maxEnd, nums[i] + i);
			}
		}
		return 0;
	}
};