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
    bool rotateString(string A, string B)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (A.size() != B.size())
                return false;
            if (A == B)
                return true;
            for (int i = 1; i < A.size(); ++i)
                if (A.substr(i) + A.substr(0, i) == B)
                    return true;
            return false;
        }
        else if (choose == 1)
        {
            return A.size() == B.size() && (A + A).find(B);
        }
    }
};