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
    vector<int> original, v;

  public:
    Solution(vector<int> nums) : original(nums), v(nums)
    {
    }
        /** Resets the array to its original configuration and return it. */
        vector<int>
        reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        next_permutation(v.begin(), v.end());
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

