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
	vector<vector<int>> permute(vector<int>& nums)
	{
		int choose = 0;
		if (choose == 0)
		{
			if (nums.empty())
				return ans;
			helper(nums, 0);
			return ans;
		}
		else if (choose == 1)
		{
			if (nums.empty() || nums.size() == 1)
				return { nums };
			vector<vector<int>> ans;
			vector<int> path;
			vector<bool> table(nums.size(), false);
			doPermute(nums, ans, path, table);
			return ans;
		}
		return {};
	}

private:
	vector<vector<int>> ans;//0
	void helper(vector<int>& nums, int index)//0
	{
		if (index == nums.size() - 1)
		{
			ans.emplace_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i)
		{
			swap(nums[index], nums[i]);
			helper(nums, index + 1);
			swap(nums[index], nums[i]);
		}
	}
	void doPermute(vector<int>& a, vector<vector<int>>& ans, vector<int>& path, vector<bool>& table)//1
	{
		if (path.size() == a.size())
		{
			ans.push_back(path);
			return;
		}
		for (vector<int>::size_type i = 0; i != a.size(); ++i)
		{
			if (table[i])
				continue;
			table[i] = true;
			path.push_back(a[i]);
			doPermute(a, ans, path, table);
			path.pop_back();
			table[i] = false;
		}
	}
};