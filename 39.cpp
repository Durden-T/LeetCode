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
    vector<vector<int>> ans;
    vector<int> path;

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return ans;
    }

  private:
    void helper(vector<int> &a, int target, int start)
    {
        if (!target)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < a.size() && a[i] <= target; ++i)
        {
            path.push_back(a[i]);
            helper(a, target - a[i], i);
            path.pop_back();
        }
    }
};