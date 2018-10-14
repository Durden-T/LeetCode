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
        unordered_set<int> s;
        for (int n = 0; true; ++n, k -= s.size())
        {
            s.clear();
            for (int i = 0; i <= n + 1; ++i)
            {
                s.insert(matrix[n][i]);
                s.insert(matrix[i][n]);
            }
            if (s.size() >= k)
            {
                priority_queue<int, vector<int>, less<int>> pq;
                for(int i:s)
                    pq.push(i);
                while(--k)
                    pq.pop();
                return pq.top();
            }
        }
    }
};