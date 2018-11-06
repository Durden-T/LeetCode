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
    ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(0);              // untie cin & cout
    cout.tie(0);
    return 0;
}();

class Solution
{
    struct
    {
        bool operator()(const pair<char, int> &a, const pair<char, int> &b)
        {
            return a.second > b.second;
        };
    } cmp;

  public:
    string frequencySort(string s)
    {
        vector<pair<char, int>> count(256);
        for (int i = 0; i < 256; ++i)
            count[i] = {i, 0};
        for (int c : s)
            ++count[c].second;
        sort(count.begin(), count.end(), cmp);
        for (int i = 0, j = 0; i < 256 && count[i].second; ++i)
            while (count[i].second)
            {
                --count[i].second;
                s[j++] = count[i].first;
            }
        return s;
    }
};