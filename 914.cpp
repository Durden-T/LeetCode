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
    bool hasGroupsSizeX(vector<int> &deck)
    {
        int m[10001] = {};
        for (int i : deck)
            ++m[i];
        int g = -1;
        for (int i = 1; i < 10001; ++i)
            g = g == -1 ? m[i] : gcd(g, m[i]);
        return g != 1;
    }

  private:
    int gcd(int x, int y)
    {
        return x ? gcd(y % x, x) : y;
    }
};