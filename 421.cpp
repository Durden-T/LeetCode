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

    struct TrieNode
    {
        int val;
        TrieNode *zero = nullptr, *one = nullptr;
        TrieNode(int x) : val(x) {}
    };

  public:
    int findMaximumXOR(vector<int> &nums)
    {
        int choose = 0;

        if (choose == 0)
        {
            TrieNode *root = new TrieNode(0), *curNode = root;
            int ans = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                for (int j = 31; j >= 0; --j)
                    if ((nums[i] & (1 << j)) == 0)
                    {
                        if (!curNode->zero)
                            curNode->zero = new TrieNode(0);
                        curNode = curNode->zero;
                    }
                    else
                    {
                        if (!curNode->one)
                            curNode->one = new TrieNode(1);
                        curNode = curNode->one;
                    }
                curNode = root;
            }
            for (int i = 0; i < nums.size(); ++i)
            {
                int cur = 0;
                for (int j = 31; j >= 0; --j)
                {
                    int tmp = nums[i] & (1 << j);
                    if (curNode->zero && curNode->one)
                        curNode = tmp ? curNode->zero : curNode->one;
                    else
                        curNode = curNode->zero ? curNode->zero : curNode->one;
                    cur += tmp ^ (curNode->val << j);
                }
                curNode = root;
                ans = max(ans, cur);
            }
            return ans;
        }
        else if (choose == 1)
        {
            int ans = 0, mask = 0;
            for (int i = 31; i >= 0; --i)
            {
                mask = mask | (1 << i);
                unordered_set<int> set;
                for (int i : nums)
                    set.insert(i & mask);
                int tmp = ans | (1 << i);
                for (int prefix : set)
                    if (set.count(tmp ^ prefix))
                    {
                        ans = tmp;
                        break;
                    }
            }
            return ans;
        }
    }
};