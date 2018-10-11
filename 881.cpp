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
    int numRescueBoats(vector<int> &people, int limit)
    {
        int ans = 0;
        sort(people.begin(), people.end());
        for (int i = 0, j = people.size() - 1; i <= j; --j, ++ans)
            if (people[i] + people[j] <= limit)
                ++i;
        return ans;
    }
};
