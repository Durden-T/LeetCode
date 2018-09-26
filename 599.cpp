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
#include <cstring>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        vector<string> ans;
        int min = INT_MAX;
        if (list1.size() > list2.size())
            list1.swap(list2);
        unordered_map<string, int> m;
        for (int i = 0; i < list2.size(); ++i)
            m[list2[i]] = i;
        for (int i = 0, t; i <= min && i < list1.size(); ++i)
            if (m.count(list1[i]))
            {
                int t = m[list1[i]] + i;
                if (t < min)
                {
                    min = t;
                    ans.clear();
                    ans.push_back(list1[i]);
                }
                else if (t == min)
                    ans.push_back(list1[i]);
            }
        return ans;
    }
};