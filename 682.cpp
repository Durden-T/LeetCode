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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int calPoints(vector<string> &ops)
    {
        vector<int> rlt;
        for (const string &o : ops)
        {
            if (o == "C")
                rlt.pop_back();
            else if (o == "D")
                rlt.push_back(rlt.back() * 2);
            else if (o == "+")
                rlt.push_back(rlt.back() + rlt[rlt.size() - 2]);
            else
                rlt.push_back(stoi(o));
        }
        return accumulate(rlt.begin(), rlt.end(), 0);
    }
};