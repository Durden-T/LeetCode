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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	bool isCousins(TreeNode* root, int x, int y)
	{
		dfs(root, nullptr);
		return depth[x] == depth[y] && parent[x] != parent[y];
	}
private:
	unordered_map<int, int> depth;
	unordered_map<int, TreeNode*> parent;
	void dfs(TreeNode* node, TreeNode* par) 
	{
		if (node) 
		{
			depth.emplace(node->val, par? 1 + depth[par->val] : 0);
			parent.emplace(node->val, par);
			dfs(node->left, node);
			dfs(node->right, node);
		}
	}
};