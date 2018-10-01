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

class Solution
{
    int ans = INT_MAX;

  public:
    int minDiffInBST(TreeNode *root)
    {
        int choose = 0;
        if (choose == 0)
        {
            helper1(root->left, root->val);
            helper1(root->right, root->val);
            return ans;
        }

        else if (choose == 1)
        {
            int res = INT_MAX, pre = -1;
            helper2(root, res, pre);
            return res;
        }

        else if (choose == 2)
        {
            vector<int> m;
            deepth(root, m);
            int ans = INT_MAX;
            int i = 1;
            for (; i < m.size(); ++i)
                ans = min(ans, m[i] - m[i - 1]);
            return ans;
        }
    }

  private:
    void helper1(TreeNode *root, int val)
    {
        if (!root)
            return;
        if (root->val == val)
        {
            ans = 0;
            return;
        }

        if (root->val < val && root->right)
        {
            TreeNode *t = root;
            while (t->right)
                t = t->right;
            ans = min(ans, abs(t->val - val));
        }
        else if (root->val > val && root->left)
        {
            TreeNode *t = root;
            while (t->left)
                t = t->left;
            ans = min(ans, abs(t->val - val));
        }
        else
            ans = min(ans, abs(val - root->val));
        helper1(root->left, root->val);
        helper1(root->right, root->val);
    }

    void helper2(TreeNode *root, int &res, int &pre)
    {
        if (!root)
            return;
        helper2(root->left, res, pre);
        if (pre != -1)
            res = min(res, (root->val - pre));
        pre = root->val;
        helper2(root->right, res, pre);
    }

    void deepth(TreeNode *root, vector<int> &m)
    {
        if (root->left)
            deepth(root->left, m);
        m.push_back(root->val);
        if (root->right)
            deepth(root->right, m);
    }
};