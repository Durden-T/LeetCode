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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    set<int> ans1;
    vector<int> ans2;

  public:
    bool findTarget(TreeNode *root, int k)
    {
        int choose = 1;
        if (choose == 0)
        {
            return helper(root, k);
        }

        else if (choose == 1)
        {
            inorder(root);
            int l = 0, r = ans2.size() - 1;
            while (l < r)
                if (ans2[l] + ans2[r] < k)
                    ++l;
                else if (ans2[l] + ans2[r] > k)
                    --r;
                else
                    return true;
            return false;
        }
    }

  private:
    bool helper(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (ans1.count(k - root->val))
            return true;
        ans1.insert(root->val);
        return helper(root->left, k) || helper(root->right, k);
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans2.push_back(root->val);
        inorder(root->right);
    }
};



static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    set<int> ans1;
    list<int> ans2;

  public:
    bool findTarget(TreeNode *root, int k)
    {
        int choose = 1;
        if (choose == 0)
        {
            return helper(root, k);
        }

        else if (choose == 1)
        {
            inorder(root);
            auto l = ans2.begin(), r = ans2.end();
            advance(r, -1);
            while (distance(l, r) > 0)
                if (*l + *r < k)
                    ++l;
                else if (*l + *r > k)
                    --r;
                else
                    return true;
            return false;
        }
    }

  private:
    bool helper(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (ans1.count(k - root->val))
            return true;
        ans1.insert(root->val);
        return helper(root->left, k) || helper(root->right, k);
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans2.push_back(root->val);
        inorder(root->right);
    }
};