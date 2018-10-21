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
    vector<int> grayCode(int n)
    {
        if (n <= 0)
            return {0};
        vector<int> ans = {0, 1};
        for (int i = 1, k = 2; i < n; i++, k <<= 1)
            for (int j = ans.size() - 1; j >= 0; j--)
                ans.emplace_back(ans[j] + k);
        return ans;
    }
};