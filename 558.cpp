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
        if (q1->isLeaf)
            return q1->val ? new Node(true, true, nullptr, nullptr, nullptr, nullptr) : q2;
        if (q2->isLeaf)
            return q2->val ? new Node(true, true, nullptr, nullptr, nullptr, nullptr) : q1;

        Node *t = new Node();
        t->topLeft = intersect(q1->topLeft, q2->topLeft);
        t->topRight = intersect(q1->topRight, q2->topRight);
        t->bottomLeft = intersect(q1->bottomLeft, q2->bottomLeft);
        t->bottomRight = intersect(q1->bottomRight, q2->bottomRight);

        if (t->topLeft->isLeaf && t->topLeft->val && t->topRight->isLeaf && t->topRight->val && t->bottomLeft->isLeaf && t->bottomLeft->val && t->bottomRight->isLeaf && t->bottomRight->val)
            t->val = t->isLeaf = true;
        return t;
    }
};