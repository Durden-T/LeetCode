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
    int reverse(int x)
    {
        int choose = 1;
        if (choose == 0)
        {
            string str = (x > 0) ? to_string(x) : to_string(-x);
            std::reverse(str.begin(), str.end());
            try
            {
                return (x > 0) ? stoi(str) : stoi("-" + str);
            }
            catch (out_of_range)
            { //let native c++ handle overflow
                return 0;
            }
        }
        else if (choose == 1)
        {
            long long result = 0;
            while (x)
            {
                result = 10 * result + x % 10;
                x = x / 10;
            }
            return (result > INT_MAX || result < INT_MIN) ? 0 : result;
        }
        else if (choose == 2)
        {
            int rev = 0;
            while (x)
            {
                int pop = x % 10;
                x /= 10;
                if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                    return 0;
                if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                    return 0;
                rev = rev * 10 + pop;
            }
            return rev;
        }
    }
};