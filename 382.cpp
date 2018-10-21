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
  private:
    ListNode *head;

  public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int ans = head->val;
        ListNode *node = head->next;
        int i = 2;
        while (node)
        {
            int j = rand() % i++;
            if (!j)
                ans = node->val;
            node = node->next;
        }
        return ans;
    }
};