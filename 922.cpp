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
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        for (int i = 0, j = 1; i < A.size(); i += 2)
            if (A[i] & 1)
            {
                while (A[j] & 1)
                    j += 2;
                swap(A[i], A[j]);
            }
        return A;
    }
};