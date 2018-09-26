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
#include<cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

static bool mark[200001];
class Solution
{
  public:
    int distributeCandies(vector<int> &candies)
    {
        memset(mark, false, sizeof(mark));
        int ans = 0;
        for (int x : candies)
            if (!mark[x + 100000])
            {
                ++ans;
                mark[x + 100000] = true;
                if (ans == candies.size() >> 1)
                    return ans;
            }
        return ans;
    }
};