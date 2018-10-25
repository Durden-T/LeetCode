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
    int maxRotateFunction(vector<int> &A)
    {
        if (A.size() < 2)
            return 0;
        int sum = 0, dp = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            sum += A[i];
            dp += i * A[i];
        }
        int ans = max(INT_MIN, dp);
        for (int i = 0; i < A.size(); ++i)
        {
            dp += sum - A.size() * A[A.size() - 1 - i];
            ans = max(ans, dp);
        }
        return ans;
    }
};