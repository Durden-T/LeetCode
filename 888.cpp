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
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int suma = accumulate(A.begin(), A.end(), 0), sumb = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> mapb(B.begin(), B.end());
        for (int i : A)
        {
            int candidateb = (sumb - suma + 2 * i) / 2;
            if (mapb.count(candidateb))
                return {i, candidateb};
        }
    }
};