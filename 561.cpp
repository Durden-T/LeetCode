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
    int ans = 0;

  public:
    int findTilt(TreeNode *root)
    {
        if (!root)
            return 0;
        sumUp(root);
        helper(root);
        return ans;
    }

  private:
  void sumUp(TreeNode *root)
    {
        if (!root)
            return;
        sumUp(root->left);
        sumUp(root->right);
        root->val += root->left ? root->left->val : 0 + root->right ? root->right->val : 0;
        if(root->)
        ans+=abs(root->)
    }
};