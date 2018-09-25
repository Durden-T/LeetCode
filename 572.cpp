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
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        bool ans = isSubtree(s->left, t) || isSubtree(s->right, t);
        if (s->val == t->val)
            ans |= isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
        return ans;
    }
};

class Solution
{
  public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return s->val == t->val ? isSubtree(s->left, t->left) && isSubtree(s->right, t->right) || isSubtree(s->left, t) || isSubtree(s->right, t) : isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};