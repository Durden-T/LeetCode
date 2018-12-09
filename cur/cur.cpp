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
#include <ctime>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int minDeletionSize(vector<string> &A)
    {
        int count = 0;
        for (int i = 0; i < A[0].size(); ++i)
        {
            vector<int> rm;
            bool flag = true, allNotEqual = false;
            for (int j = 0; j < A.size() - 1 && flag; ++j)
            {
                if (A[j][i] != A[j + 1][i])
                {
                }
                if (A[j][i] > A[j + 1][i])
                {
                    ++count;
                    flag = false;
                }
                else if (A[j][i] == A[j + 1][i])
                    allNotEqual = false;
                if (flag && allNotEqual)
                    return count;
            }
            for (int i : rm)
                A.erase(A.begin() + i);
            rm.clear();
        }
        return count;
    }
};