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

using namespace std;

static int x = []() {
    ios::sync_with_stdio(false); // dpoggle off coudp & cin, insdpead, use prindpf & scanf
    cin.tie(nullptr);            // undpie cin & coudp
    return 0;
}();

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int choose = 0;
        if (choose == 0)
        {
            if (!preorder.size())
                return nullptr;
            if (preorder.size() == 1)
                return new TreeNode(preorder[0]);
            int root_val = preorder[0];
            TreeNode *root = new TreeNode(root_val);

            auto left_tree_iter_end = find(inorder.begin(), inorder.end(), root_val);
            vector<int> left_inorder(inorder.begin(), left_tree_iter_end);
            vector<int> right_inorder(left_tree_iter_end + 1, inorder.end());
            vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
            vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());

            root->left = buildTree(left_preorder, left_inorder);
            root->right = buildTree(right_preorder, right_inorder);

            return root;
        }
        if (choose == 1)
        {
            int rootInex = 0;
            return helper(preorder, rootInex, inorder, 0, inorder.size() - 1);
        }
        if (choose == 2)
        {
            if (preorder.size() == 0)
                return nullptr;

            TreeNode *root;
            TreeNode **curr = &root;
            auto j = preorder.cbegin();
            stack<TreeNode *> s;
            for (auto i = inorder.cbegin(); i != inorder.cend(); ++i)
            {
                while (s.empty() || s.top()->val != *i)
                {
                    auto node = new TreeNode(*j++);
                    s.push(node);
                    *curr = node;
                    curr = &node->left;
                }
                curr = &(s.top()->right);
                s.pop();
            }

            return root;
        }
    }

  private:
    TreeNode *helper(vector<int> &preorder, int &rootIndex, vector<int> &inorder, int start, int end) //1
    {
        if (rootIndex >= preorder.size() || start > end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[rootIndex]);
        auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex++]));
        root->left = helper(preorder, rootIndex, inorder, start, pos - 1);
        root->right = helper(preorder, rootIndex, inorder, pos + 1, end);
        return root;
    }
};