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

class Solution
{
  public:
    Node *flatten(Node *head)
    {
        int choose = 0;
        if (choose == 0)
        {
            if (!head)
                return nullptr;
            helper(head);
            return head;
        }
        else if (choose == 1)
        {
            for (Node *cur = head; cur; cur = cur->next)
                if (cur->child)
                {
                    Node *next = cur->next;
                    cur->next = cur->child;
                    cur->next->prev = cur;
                    cur->child = nullptr;
                    Node *prev = cur->next;
                    while (prev->next)
                        prev = prev->next;
                    if (next)
                    {
                        prev->next = next;
                        next->prev = prev;
                    }
                }
            return head;
        }
    }

  private:
    Node *helper(Node *head)
    {
        if (!head->next && !head->child)
            return head;
        if (head->child)
        {
            Node *tail = helper(head->child);
            tail->next = head->next;
            head->next = head->child;
            head->next->prev = head;
            head->child = nullptr;
            if (tail->next)
            {
                tail->next->prev = tail;
                return helper(tail->next);
            }
            return tail;
        }
        return helper(head->next);
    }
};