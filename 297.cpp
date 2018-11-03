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

class CodecStream
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

  private:
    enum STATUS
    {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };

    void serialize(TreeNode *root, ostringstream &out)
    {
        char status = 0;
        if (root)
            status |= ROOT;
        if (root && root->left)
            status |= LEFT;
        if (root && root->right)
            status |= RIGHT;
        out.write(&status, sizeof(char));
        if (!root)
            return;
        out.write(reinterpret_cast<char *>(&(root->val)), sizeof(root->val));
        if (root->left)
            serialize(root->left, out);
        if (root->right)
            serialize(root->right, out);
    }

    TreeNode *deserialize(istringstream &in)
    {
        char status;
        in.read(&status, sizeof(char));
        if (!status & ROOT)
            return nullptr;
        auto root = new TreeNode(0);
        in.read(reinterpret_cast<char *>(&root->val), sizeof(root->val));
        root->left = (status & LEFT) ? deserialize(in) : nullptr;
        root->right = (status & RIGHT) ? deserialize(in) : nullptr;
        return root;
    }
};

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int pos = 0;
        return deserialize(data, pos);
    }

  private:
    enum STATUS
    {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };

    void serialize(TreeNode *root, string &s)
    {
        char status = ROOT_NULL;
        if (root)
            status |= ROOT;
        if (root && root->left)
            status |= LEFT;
        if (root && root->right)
            status |= RIGHT;
        s.push_back(status);
        if (!root)
            return;
        s.append(reinterpret_cast<char *>(&root->val), sizeof(root->val));
        if (root->left)
            serialize(root->left, s);
        if (root->right)
            serialize(root->right, s);
    }

    TreeNode *deserialize(const string &s, int &pos)
    {
        char status = s[pos++];
        if (!status)
            return nullptr;
        TreeNode *root = new TreeNode(0);
        memcpy(&root->val, &s[pos], sizeof(root->val));
        pos += sizeof(root->val);
        root->left = (status & LEFT) ? deserialize(s, pos) : nullptr;
        root->right = (status & RIGHT) ? deserialize(s, pos) : nullptr;
        return root;
    }
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class CodecSpace
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

  private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (root == nullptr)
        {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode *deserialize(istringstream &in)
    {
        string val;
        in >> val; // split by space
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};