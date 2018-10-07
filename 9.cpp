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
    bool isPalindrome(int x)
    {
        if (x < 0 || !(x % 10) && x)
            return false;
        if (x < 10)
            return true;
        int y = 0;
        while (x > y)
        {
            y = y * 10 + x % 10;
            x = x / 10;
            if (x == y || x == y / 10)
                return true;
        }
        return false;
    }
};