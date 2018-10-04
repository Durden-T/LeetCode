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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int choose = 0;
        if (choose == 0)
        {
            if (matrix.empty() || matrix[0].empty())
                return false;
            int i = 0, j = matrix.size() - 1, c;
            while (i <= j)
            {
                c = (i + j) / 2;
                if (matrix[c][0] > target)
                    j = c - 1;
                else if (matrix[c].back() < target)
                    i = c + 1;
                else
                    break;
            }
            if (i > j)
                return false;
            i = 0, j = matrix[0].size() - 1;
            int row = c;
            while (i <= j)
            {
                c = (i + j) / 2;
                if (matrix[row][c] > target)
                    j = c - 1;
                else if (matrix[row][c] < target)
                    i = c + 1;
                else
                    return true;
            }
            return false;
        }
        else if (choose == 1)
        {
            if (matrix.empty())
                return false;

            int row = 0;
            int col = matrix[0].size() - 1;

            while (row < matrix.size() && col >= 0)
            {
                if (matrix[row][col] == target)
                    return true;
                else if (matrix[row][col] > target)
                    --col;
                else
                    ++row;
            }
            return false;
        }
    }
};