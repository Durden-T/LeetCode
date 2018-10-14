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
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int choose = 0;
        if (choose == 0)
        {
            priority_queue<int> pq;
            for (int i = 0; i < matrix.size(); ++i)
                for (int j = 0; j < matrix[0].size(); ++j)
                {
                    pq.push(matrix[i][j]);
                    if (pq.size() > k)
                        pq.pop();
                }
            return pq.top();
        }

        else if (choose == 1)
        {
            //https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85238/Clean-solution-with-detailed-explanation-in-C++
            int le = matrix[0][0], ri = matrix.back().back();
            while (le < ri) //最后left会等于right
            {
                int mid = (le + ri) / 2, upToMid = 0;
                for (int i = 0; i < matrix.size(); ++i)
                    upToMid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                if (upToMid < k)
                    le = mid + 1;
                else //upToMid >= k
                    ri = mid;
            }
            return le;
        }
    }
};