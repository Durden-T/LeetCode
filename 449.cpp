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

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string data;
        serialize(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }

  private:
    void serialize(TreeNode *root, string &data)
    {
        if (!root)
            return;
        data.append(reinterpret_cast<char *>(&root->val), sizeof(int));
        serialize(root->left, data);
        serialize(root->right, data);
    }

    TreeNode *deserialize(const string &buffer, int &pos, int minValue, int maxValue)
    {
        if (pos == buffer.size())
            return nullptr; //using pos to check whether buffer ends is better than using char* directly.

        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue)
            return nullptr;

        TreeNode *node = new TreeNode(value);
        pos += sizeof(int);
        node->left = deserialize(buffer, pos, minValue, value);
        node->right = deserialize(buffer, pos, value, maxValue);
        return node;
    }
};