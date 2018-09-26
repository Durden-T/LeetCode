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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for(int i:nums)
            ++m[i];
        int ans = 0;
        for(auto &p:m)
            if(m.count(p.first+1))
                ans = max(ans, p.second + m[p.first + 1]);
        return ans;
    }
};