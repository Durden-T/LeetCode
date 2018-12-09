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
#include <ctime>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    struct cmp
    {
        bool operator()(const int a, const int b)
        {
            return abs(a) < abs(b);
        };
    };

  public:
    bool canReorderDoubled(vector<int> &A)
    {
        map<int, int, cmp> m;
        for (int a : A)
            ++m[a];
        for (auto &x : m)
        {
            if (x.second > m[2 * x.first])
                return false;
            m[2 * x.first] -= x.second;
        }
        return true;
    }
};