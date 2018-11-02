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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        string ans;
        sHelper(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        
    }

  private:
    void sHelper(TreeNode *root, string &ans)
    {
        if (!root)
        {
            ans += '.';
            return;
        }
        sHelper(root->left, ans);
        int t = root->val;
        if (t < 0)
        {
            ans += '-';
            t = -t;
        }
        while (t)
        {
            ans += t % 10 + '0';
            t /= 10;
        }
        t += '#';
        sHelper(root->right, ans);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));