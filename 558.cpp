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

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
  public:
    Node *intersect(Node *q1, Node *q2)
    {
        if (!q1)
            return q2;
        if (!q2)
            return q1;

        if (q1->isLeaf)
            return q1->val ? q1 : q2;
        if (q2->isLeaf)
            return q2->val ? q2 : q1;

        Node *root = new Node(false, false, nullptr, nullptr, nullptr, nullptr);

        Node *top_left = intersect(q1->topLeft, q2->topLeft);
        Node *top_right = intersect(q1->topRight, q2->topRight);
        Node *bottom_left = intersect(q1->bottomLeft, q2->bottomLeft);
        Node *bottom_right = intersect(q1->bottomRight, q2->bottomRight);

        if (top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf & bottom_right->isLeaf &&
            top_left->val == top_right->val && top_left->val == bottom_left->val && top_left->val == bottom_right->val)
        {
            root->isLeaf = true;
            root->val = top_left->val;
        }
        else
        {
            root->topLeft = top_left;
            root->topRight = top_right;
            root->bottomLeft = bottom_left;
            root->bottomRight = bottom_right;
        }

        return root;
    }
};