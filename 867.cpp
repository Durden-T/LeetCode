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
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> B(A[0].size(), vector<int>(A.size()));
        for (int j = 0; j < A[0].size(); ++j)
            for (int i = 0; i < A.size(); ++i)
                B[j][i] = A[i][j];
        return B;
    }
};