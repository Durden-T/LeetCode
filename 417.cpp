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

/*
        mark[m][n] <- 0 : 00 <- untouched  01<- pacific only 10 <- atlantic only 11 <- both. 
        for i <- 0..m and j <- 0:
            helper() upwards and visit new nodes
        for i <- 0 and j <- 0..n:
            helper() upwards and visit new nodes
        do the same for right edge and bottom edge and mark atlantic.
        
        iterate all nodes and list the nodes that can be reached by both.
            
    */
class Solution
{
    vector<pair<int, int>> ans;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    enum
    {
        Pacific = 1,
        Atlantic,
        both
    };

  public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); ++i)
        {
            helper(matrix, table, i, 0, Pacific);
            helper(matrix, table, i, matrix[0].size() - 1, Atlantic);
        }

        for (int i = 0; i < matrix[0].size(); ++i)
        {
            helper(matrix, table, 0, i, Pacific);
            helper(matrix, table, matrix.size() - 1, i, Atlantic);
        }

        return ans;
    }

  private:
    void helper(vector<vector<int>> &matrix, vector<vector<int>> &table, int i, int j, int ocean)
    {
        if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size() || table[i][j] == ocean)
            return;

        if (table[i][j] != both && (table[i][j] |= ocean) == both)
            ans.emplace_back(i, j);

        for (int k = 0; k < 4; ++k)
        {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[i][j] <= matrix[ni][nj])
                helper(matrix, table, ni, nj, table[i][j]);
        }
    }
};