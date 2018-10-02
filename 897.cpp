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
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

/*class Solution
{
  public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root->right)
            root->right = increasingBST(root->right);
        if (!root->left)
            return root;
        TreeNode *head = increasingBST(root->left), *t = head;
        root->left = nullptr;
        while (t->right)
            t = t->right;
        t->right = root;
        return head;
    }
};*/

class Solution
{
  public:
    TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr)
    {
        if (!root)
            return tail;
        TreeNode *ans = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, tail);
        return ans;
    }
};