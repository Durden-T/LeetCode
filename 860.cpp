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
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (int val : bills)
            if (val == 5)
                ++five;
            else if (val == 10)
            {
                if (!five--)
                    return false;
                ++ten;
            }
            else
            {
                if (ten && five)
                {
                    --ten;
                    --five;
                }
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        return true;
    }
};