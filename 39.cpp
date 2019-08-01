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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> path;
		helper(0, target, candidates, path, ans);
		return ans;
	}
private:
	void helper(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans)
	{
		if (!target)
		{
			ans.push_back(path);
			return;
		}
		for (int i = start; i < candidates.size() && candidates[i] <= target; ++i)
		{
			path.push_back(candidates[i]);
			helper(i, target - candidates[i], candidates, path, ans);
			path.pop_back();
		}
	}
};