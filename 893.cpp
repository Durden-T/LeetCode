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
    // HINT: all you need to do is get an encoding for each string such that
    // the even and odd indices are separated and the order in left or in right doesnt matter
    // finally use a map or a set to get the final number
    int numSpecialEquivGroups(vector<string> &A)
    {
        set<vector<int>> res;
        int C = A[0].size();
        for (int i = 0; i < A.size(); ++i)
        {
            vector<int> freq(52, 0);
            for (int j = 0; j < C; ++j)
                ++freq[A[i][j] - 'a' + (26 * (j % 2))];
            res.insert(freq);
        }
        return res.size();
    }
};
