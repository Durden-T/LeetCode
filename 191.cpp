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
    int hammingWeight(int n)
    {
        int choose = 1;
        if (choose == 0)
        {
            int ans = 0;
            while (n)
            {
                if (n & 1)
                    ++ans;
                n >>= 1;
            }
            return ans;
        }
        else if (choose == 1)
        {
            int ans = 0;
            while (n)
            {
                ++ans;
                n &= n - 1;
            }
            return ans;
        }
    }
};