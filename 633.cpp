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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    bool judgeSquareSum(int c)
    {
        int choose = 1;
        if (choose == 0)
        {
            int limit = (sqrt(c / 2 + 1) + 1.5);
            for (long long i = 0; i <= limit; ++i)
            {
                double j = sqrt(c - i * i);
                if (j == (int)j)
                    return true;
            }
            return false;
        }
        else if (choose == 1)
        {
            int lo = 0, hi = sqrt(c);
            while (lo <= hi)
            {
                int cur = lo * lo + hi * hi;
                if (cur < c)
                    ++lo;
                else if (cur > c)
                    --hi;
                else
                    return true;
            }
            return false;
        }
    }
};