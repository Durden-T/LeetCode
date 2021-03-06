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
    int lastRemaining(int n, bool flag = true)
    {
        return leftToRight(n);
    }

  private:
    int leftToRight(int n)
    {
        if (n <= 2)
            return n;
        return 2 * rightToLeft(n / 2);
    }

    int rightToLeft(int n)
    {
        if (n <= 2)
            return 1;
        if (n % 2 == 1)
            return 2 * leftToRight(n / 2);
        return 2 * leftToRight(n / 2) - 1;
    }
};