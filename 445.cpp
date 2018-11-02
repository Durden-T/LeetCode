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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *ans, *p = l1, *q = l2;
        while (p)
        {
            p = p->next;
            ++n1;
        }
        p = l1;
        while (q)
        {
            q = q->next;
            ++n2;
        }
        q = l2;
        int dif = abs(n1 - n2);
        if (dif)
        {
            if (n1 < n2)
            {
                p = l2;
                q = l1;
            }
            while (dif--)
            {
                ListNode *t = new ListNode(0);
                t->next = q;
                q = t;
            }
        }
        ans = helper(p, q, carry);
        if (carry)
        {
            ListNode *t = new ListNode(carry);
            t->next = ans;
            ans = t;
        }
        return ans;
    }

  private:
    ListNode *helper(ListNode *p, ListNode *q, int &carry)
    {
        if (!p)
            return nullptr;
        ListNode *t = new ListNode(0);
        t->next = helper(p->next, q->next, carry);
        int sum = p->val + q->val + carry;
        carry = sum / 10;
        t->val = sum % 10;
        return t;
    }
};