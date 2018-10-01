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
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        if (A == B)
        {
            int map[26] = {0};
            for (int i : A)
                if (++map[i - 'a'] > 1)
                    return true;
            return false;
        }
        int first = -1, i = 0;
        while (i < A.size())
        {
            if (A[i] != B[i])
            {
                if (first == -1)
                    first = i;
                else
                {
                    swap(A[i], A[first]);
                    if (A[i] != B[i] || A[first] != B[first])
                        return false;
                    else
                        break;
                }
            }
            ++i;
        }
        if (i == A.size())
            return false;
        while (i < A.size() && A[i] == B[i])
            ++i;
        return i == A.size();
    }
};