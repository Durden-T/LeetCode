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
#include <bits>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class MyLinkedList
{
  public:
    /** Initialize your data structure here. */
    MyLinkedList()
        : m_Head(nullptr)
    {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        Node *currentNode = m_Head.get();
        while (currentNode != nullptr && index >= 0)
        {
            if (index == 0)
            {
                return currentNode->m_Value;
            }

            --index;
            currentNode = currentNode->m_Next.get();
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        unique_ptr<Node> newHead(new Node(val));
        newHead->m_Next = move(m_Head);
        m_Head = move(newHead);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *currentNode = m_Head.get();
        while (currentNode->m_Next)
        {
            currentNode = currentNode->m_Next.get();
        }

        unique_ptr<Node> newTail(new Node(val));
        currentNode->m_Next = move(newTail);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *currentNode = m_Head.get();
        Node *prevNode = nullptr;
        while (currentNode != nullptr && index >= 0)
        {
            if (index == 0)
            {
                unique_ptr<Node> newNode(new Node(val));
                newNode->m_Next = move(prevNode->m_Next);
                prevNode->m_Next = move(newNode);
                return;
            }
            --index;
            prevNode = currentNode;
            currentNode = currentNode->m_Next.get();
        }
        if (index == 0)
        {
            unique_ptr<Node> newNode(new Node(val));
            prevNode->m_Next = move(newNode);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            m_Head = move(m_Head->m_Next);
            return;
        }

        Node *currentNode = m_Head.get();
        Node *prevNode = nullptr;
        while (currentNode != nullptr && index >= 0)
        {
            if (index == 0)
            {
                prevNode->m_Next = move(currentNode->m_Next);
                return;
            }
            --index;
            prevNode = currentNode;
            currentNode = currentNode->m_Next.get();
        }
    }

  private:
    struct Node
    {
        int m_Value;
        unique_ptr<Node> m_Next;
        Node(int val) : m_Value(val), m_Next(nullptr) {}
    };
    unique_ptr<Node> m_Head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */