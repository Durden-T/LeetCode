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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        if (A.size() < 3)
            return 0;
        int ans = 0, cur = A[1] - A[0], i = 0;
        for (int j = 2; j < A.size(); ++j)
            if (A[j] - A[j - 1] != cur)
            {
                ans += (j - i - 2) * (j - i - 1) / 2;
                i = j - 1;
                cur = A[j] - A[i];
            }
        return A[A.size() - 1] - A[A.size() - 2] == cur ? ans + (A.size() - i - 2) * (A.size() - i - 1) / 2 : ans;
    }
};