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
    vector<int> A;
    Solution(vector<int> v) : A(v) {}

    int pick(int Target)
    {
        int ans;
        for (int i = 0, cnt = 0; i < A.size(); ++i)
            if (A[i] == Target && !(rand() % ++cnt))
                ans = i;
        return ans;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
/*class Solution
{
    unordered_map<int, vector<int>> mp;

  public:
    Solution(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]].push_back(i);
    }

    int pick(int target)
    {
        auto &v = mp[target];
        return v[rand() % v.size()];
    }
};*/
