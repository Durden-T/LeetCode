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
    int countPrimeSetBits(int L, int R)
    {
        int ans = 0;
        while (L <= R)
            if (isPrime(__builtin_popcount(L++)))
                ++ans;
        return ans;
    }

  private:
    bool isPrime(int n)
    {
        if (n == 2)
            return true;
        if (n == 1 || !(n & 1))
            return false;
        int limit = sqrt(n);
        for (int i = 3; i <= limit; i += 2)
            if (!(n % i))
                return false;
        return true;
    }
};