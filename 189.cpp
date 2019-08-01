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

static int __initialSetup = [] {
	ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(0);              // untie cin & cout
	cout.tie(0);
	return 0;
}();

class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		int choose = 0;
		if (choose == 0)
		{
			int n = nums.size();
			auto start = nums.begin();
			for (; k %= n; n -= k, start += k)

				// Swap the last k elements with the first k elements. 
				// The last k elements will be in the correct positions
				// but we need to rotate the remaining (n - k) elements 
				// to the right by k steps.
				for (int i = 0; i < k; i++)
					swap(start[i], start[n - k + i]);
		}
		else if (choose == 1)
		{
			k %= nums.size();
			reverse(nums.begin(), nums.end());
			reverse(nums.begin(), nums.begin() + k);
			reverse(nums.begin() + k, nums.end());
		}
	}
};