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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        //1-> 2 -> 3 -> 4 -> 5 -> NULL, m = 2, n = 4
        //pre node      q    p
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *pre = new_head, *node = head;
        int i = 1;
        while (i < m)
        {
            pre = node;
            node = node->next;
            ++i;
        }

        ListNode *q = nullptr;
        ListNode *p = node;
        for (int i = m; i <= n; ++i)
        {
            ListNode *t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        pre->next = q;
        node->next = p;
        return new_head->next;
    }
};
