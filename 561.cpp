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
        GetTreeSum(root);
        return ans;
    }

  private:
    int GetTreeSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int lSum = GetTreeSum(root->left);
        int rSum = GetTreeSum(root->right);
        ans += abs(lSum - rSum);
        return lSum + root->val + rSum;
    }
};