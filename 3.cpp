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

static int __initialSetup = []() {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int choose = 1;
        if (choose == 0)
        {
            int map[128] = {};
            int begin = 0, end = 0, counter = 0, d = 0;
            while (end < s.size())
            {
                if (map[s[end++]]++ > 0)
                    ++counter;
                while (counter > 0)
                    if (map[s[begin++]]-- > 1)
                        --counter;
                d = max(d, end - begin);
            }
            return d;
        }
        else if (choose == 1)
        {
            int ans = 0, index[128] = {};
            for (int j = 0, i = 0; j < s.size(); ++j)
            {
                i = max(index[s[j]], i);
                ans = max(ans, j - i + 1);
                index[s[j]] = j + 1;
            }
            return ans;
        }
    }
};