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
    bool isSubsequence(string s, string t)
    {
        int lenS = s.length();
        int lenT = t.length();
        if (!lenT)
            return true;
        if (!lenS)
            return false;

        unordered_map<char, vector<int>> mymap;

        for (int i = 0; i < lenT; i++)
        {
            mymap[t[i]].push_back(i);
        }
        //constructed the map Now check the subsequence
        int prevIndex = -1;
        for (int i = 0; i < lenS; i++)
        {
            if (mymap[s[i]].empty())
                return false;
            int newIndex = -1;
            int cnt = 0;
            while (cnt < mymap[s[i]].size())
            {
                newIndex = mymap[s[i]][cnt++];
                if (newIndex > prevIndex)
                {
                    prevIndex = newIndex;
                    break;
                }
            }

            if (newIndex == -1 || newIndex < prevIndex)
                return false;
        }

        return true;
    }
};
