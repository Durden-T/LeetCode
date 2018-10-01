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
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double ans = 0;
        for (int i = 0; i < points.size() - 2; ++i)
            for (int j = i + 1; j < points.size() - 1; ++j)
                for (int k = j + 1; k < points.size(); ++k)
                    ans = max(ans, 0.5 * abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0] - points[k][1] * points[i][0]));
        return ans;
    }
};