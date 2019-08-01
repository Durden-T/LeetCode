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
    ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(0);              // untie cin & cout
    cout.tie(0);
    return 0;
}();

class Solution
{
  public:
    int minDeletionSize(vector<string> &A)
    {
        //previous col is sorted then is over
        int ans = 0;
        for (int j = 0; j < A[0].size(); ++j)
        {
            bool need_next = false;
            int i = 1;
            for (; i < A.size(); ++i)
                if (A[i].substr(0, j + 1) < A[i - 1].substr(0, j + 1))
                {
                    ++ans;
                    break;
                }
                else if (A[i].substr(0, j) == A[i - 1].substr(0, j))
                    need_next = true;

            if (i == A.size() && !need_next)
                return ans; //sorted
            if (i < A.size())
                for (int k = 0; k < A.size(); ++k)
                    A[k][j] = '*';
        }
        return ans;
    }
};