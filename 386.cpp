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
    vector<int> lexicalOrder(int n)
    {
        int choose = 1;
        if (choose == 0)
        {
            vector<int> ans;
            for (int i = 1; i < 10; ++i)
                helper(i, n, ans);
            return ans;
        }

        else if (choose == 1)
        {
            vector<int> ans(n, 0);
            int cur = 1;
            for (int i = 0; i < n; ++i)
            {
                ans[i] = cur;
                if (cur * 10 <= n)
                    cur *= 10;
                else
                {
                    if (cur >= n)
                        cur /= 10;
                    ++cur;

                    while (cur % 10 == 0)
                        cur /= 10;
                }
            }
            return ans;
        }

        else if (choose == 2)
        {
            vector<int> ans(n);
            int *first = &ans[0];
            iota(first, first + n, 1);
            for (int ok = 9; ok < n; ok = 10 * ok + 9)
                inplace_merge(first,
                              first + ok,
                              first + min(ok * 10 + 9, n),
                              [ok](int a, int b) {
                                  while (b <= ok)
                                      b *= 10;
                                  return a < b;
                              });
            return ans;
        }
    }

  private:
    void helper(int cur, int n, vector<int> &ans)
    {
        if (cur > n)
            return;
        ans.push_back(cur);
        cur *= 10;
        for (int i = 0; i < 10; ++i)
            helper(cur + i, n, ans);
    }
};