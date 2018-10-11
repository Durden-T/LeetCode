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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int choose = 1;
        if (choose == 0)
        {
            int n = nums.size();
            vector<int> fromBegin(n), fromLast(n), res(n);
            fromBegin[0] = fromLast[0] = 1;
            for (int i = 1; i < n; ++i)
            {
                fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
                fromLast[i] = fromLast[i - 1] * nums[n - i];
            }
            for (int i = 0; i < n; ++i)
                res[i] = fromBegin[i] * fromLast[n - 1 - i];
            return res;
        }

        else if (choose == 1)
        {
            int n = nums.size(), fromBegin = 1, fromLast = 1;
            vector<int> res(n, 1);
            for (int i = 0; i < n; ++i)
            {
                res[i] *= fromBegin;
                fromBegin *= nums[i];
                res[n - 1 - i] *= fromLast;
                fromLast *= nums[n - 1 - i];
            }
            return res;
        }
    }
};