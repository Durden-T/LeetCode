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

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return s && (equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));

        /*string tree1 = preorder(s);
        string tree2 = preorder(t);
        return tree1.find(tree2) != string::npos;*/
    }

  private:
    bool equal(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return s->val == t->val && equal(s->left, t->left) && equal(s->right, t->right);
    }
    string preorder(TreeNode *t)
    {
        if (!t)
            return "e";
        return "#" + to_string(t->val) + " " + preorder(t->left) + " " + preorder(t->right);
    }
};