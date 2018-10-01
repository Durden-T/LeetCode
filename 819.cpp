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
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> M;
        int count = 0;
        string s, ans;

        for (string &s : banned)
            for (char &c : s)
                c = tolower(c);

        for (string &s : banned)
            M[s] = INT_MIN;
        paragraph += ' ';
        for (char c : paragraph)
            if (isalpha(c))
                s += tolower(c);
            else if (!s.empty())
            {
                if (++M[s] > count)
                {
                    count = M[s];
                    ans = s;
                }
                s.clear();
            }
        return ans;
    }
};