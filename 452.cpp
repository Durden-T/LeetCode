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
    ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(0);              // untie cin & cout
    cout.tie(0);
    return 0;
}();

class Solution
{
  public:
    int findMinArrowShots(vector<pair<int, int>> &points)
    {
        if (points.size() < 2)
            return points.size();
        sort(points.begin(), points.end());
        int ans = 1, cur = points[0].second;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].first > cur)
            {
                ++ans;
                cur = points[i].second;
            }
            cur = min(points[i].second, cur);
        }
        return ans;
    }
};