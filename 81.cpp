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
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            while (l < r && nums[l] == nums[l + 1])
                ++l; // skip duplicates from the left
            while (r > l && nums[r] == nums[r - 1])
                --r; // skip duplicates from the right
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > target)
                if (nums[l] <= target || nums[mid] < nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            else if (nums[l] > target || nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};