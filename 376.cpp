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
	int wiggleMaxLength(vector<int>& nums)
	{
		int choose = 1;
		if (choose == 0)
		{
			if (nums.size() < 2)
				return nums.size();
			int prediff = nums[1] - nums[0], ans = (prediff != 0) + 1;
			for (int i = 2; i < nums.size(); ++i)
			{
				int diff = nums[i] - nums[i - 1];
				if (diff > 0 && prediff <= 0 || diff < 0 && prediff >= 0)
				{
					++ans;
					prediff = diff;
				}
			}
			return ans;
		}

		else if (choose == 1)
		{
			if (nums.size() < 2)
				return nums.size();
			int up = 1, down = 1;
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] > nums[i - 1])
					up = down + 1;
				else if (nums[i] < nums[i - 1])
					down = up + 1;
			}
			return max(up, down);
		}
		return 0;
	}
};
