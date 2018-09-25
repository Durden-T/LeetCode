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
{
    "$id" : "1", "bottomLeft" : {"$id" : "4", "bottomLeft" : null, "bottomRight" : null, "isLeaf" : true, "topLeft" : null, "topRight" : null, "val" : true}, "bottomRight" : {"$id" : "5", "bottomLeft" : null, "bottomRight" : null, "isLeaf" : true, "topLeft" : null, "topRight" : null, "val" : false}, "isLeaf" : false, "topLeft" : {"$id" : "2", "bottomLeft" : null, "bottomRight" : null, "isLeaf" : true, "topLeft" : null, "topRight" : null, "val" : true}, "topRight" : {"$id" : "3", "bottomLeft" : null, "bottomRight" : null, "isLeaf" : true, "topLeft" : null, "topRight" : null, "val" : true}, "val" : true
}

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
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf || quadTree2->isLeaf)
        {
            quadTree1->isLeaf = true;
            quadTree1->val = quadTree1->val || quadTree2->val;
        }
        else
        {
            intersect(quadTree1->topLeft, quadTree2->topLeft);
            intersect(quadTree1->topRight, quadTree2->topRight);
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        }
        return quadTree1;
        //fucZasdasdafaddas
    }
};