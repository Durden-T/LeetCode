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
    int rotatedDigits(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            int t = i, _new = 0, limit = 1;
            bool valid = true;
            while (t /= 10)
                limit *= 10;
            t = i;
            while (valid && limit)
            {
                int cur = t / limit;
                switch (cur)
                {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                    cur = 5;
                    break;
                case 5:
                    cur = 2;
                    break;
                case 6:
                    cur = 9;
                    break;
                case 9:
                    cur = 6;
                    break;
                default:
                    valid = false;
                    break;
                }
                _new = 10 * _new + cur;
                t %= limit;
                limit /= 10;
            }
            if (valid && _new != i)
                ++ans;
        }
        return ans;
    }
};