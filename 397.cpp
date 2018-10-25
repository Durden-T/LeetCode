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
    int integerReplacement(int n)
    {
        return helper(n);
    }

  private:
    long long helper(long long n)
    {
        if (n < 2)
            return 0;
        return n & 1 ? min(helper(n + 1), helper(n - 1)) + 1 : helper(n / 2) + 1;
    }
};