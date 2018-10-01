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
    int binaryGap(int N)
    {
        int ans = 0;
        for (int i = 0, last = -1; N; ++i)
        {
            if (N & 1)
                if (last == -1)
                    last = i;
                else
                {
                    ans = max(ans, i - last);
                    last = i;
                }
            N >>= 1;
        }
        return ans;
    }
};