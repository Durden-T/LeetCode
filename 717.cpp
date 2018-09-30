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
    bool isOneBitCharacter(vector<int> &bits)
    {
        return helper(bits, 0);
    }

  private:
    bool helper(vector<int> &bits, int i)
    {
        if (i == bits.size() - 1)
            return true;
        if (i >= bits.size())
            return false;
        return bits[i] ? helper(bits, i + 2) : helper(bits, i + 1);
    }
};