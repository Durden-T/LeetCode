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
    int first;
    int second = -1;

  public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root)
            return -1;
        first = root->val;
        helper(root);
        return second;
    }

  private:
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        if (root->val != first)
            second = second != -1 ? min(second, root->val) : root->val;      
        helper(root->left);
        helper(root->right);
    }
};