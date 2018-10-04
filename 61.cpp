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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k || !head->next)
            return head;
        ListNode *tail = head, *tailPre = head, *pos = head;
        int len = 0;
        while (tail)
        {
            ++len;
            tailPre = tail;
            tail = tail->next;
        }
        int front = len - k % len;
        while (--front)
            pos = pos->next;
        tailPre->next = head;
        head = pos->next;
        pos->next = nullptr;
        return head;
    }
};