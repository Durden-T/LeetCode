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
	vector<TreeNode*> generateTrees(int n)
	{
		int choose = 0;
		if (choose == 0)
		{
			if (n <= 0)
				return {};
			vector<vector<TreeNode*>> dp(n + 1);
			dp[0] = { nullptr };
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= i; ++j)
					for (auto left : dp[j - 1])
						for (auto right : dp[i - j])
						{
							TreeNode* t = new TreeNode(j);
							t->left = left;
							t->right = helper(right, j);
							dp[i].emplace_back(t);
						}
			return dp.back();
		}
		else if (choose == 1)
		{
			if (n == 0)
				return {};
			return DFS(1, n);
		}
		/*else if (choose == 2)
		{
			if (n <= 0)
				return {};
			vector<TreeNode*> dp[100][100];
			for (int i = n + 1; i; i--)
				for (int j = i - 1; j <= n; j++)
					if (i == j)
						dp[i][j].emplace_back(move(new TreeNode(i)));
					else if (i > j)
						dp[i][j].emplace_back(nullptr);
					else
						for (int k = i; k <= j; k++)
							for (auto l : dp[i][k - 1])
								for (auto r : dp[k + 1][j])
								{
									auto node = new TreeNode(k);
									node->left = l;
									node->right = r;
									dp[i][j].emplace_back(move(node));
								}
			return dp[1][n];
		}*/
		return {};
	}

private:
	TreeNode* helper(TreeNode* root, int val)
	{
		if (!root)
			return nullptr;
		TreeNode* tmp = new TreeNode(root->val + val);
		tmp->left = helper(root->left, val);
		tmp->right = helper(root->right, val);
		return tmp;
	}

	vector<TreeNode*> DFS(int l, int r)
	{
		vector<TreeNode*> res;
		if (l > r)
			return { nullptr };
		for (int i = l; i <= r; i++)
		{
			auto left = DFS(l, i - 1);
			auto right = DFS(i + 1, r);
			for (auto x : left)
				for (auto y : right)
				{
					TreeNode* root = new TreeNode(i);
					root->left = x;
					root->right = y;
					res.push_back(root);
				}
		}
		return res;
	}
};
