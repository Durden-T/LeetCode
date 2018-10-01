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
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() - 1; ++i)
            for (int j = 0; j < matrix[0].size() - 1; ++j)
                if (matrix[i + 1][j + 1] != matrix[i][j])
                    return false;
        return true;
    }
};