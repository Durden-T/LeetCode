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
        for (string &s : banned)
            for (char &c : s)
                c = tolower(c);
        string dic;
        for (char c : paragraph)
            dic += isalpha(c) ? tolower(c) : ' ';
        istringstream ss(dic);
        string s;
        unordered_map<string, int> M;
        for (string &s : banned)
            M[s] = INT_MIN;
        int count = 0;
        string ans;
        while (ss >> s)
            if (++M[s] > count)
            {
                count = M[s];
                ans = s;
            }
        return ans;
    }
};