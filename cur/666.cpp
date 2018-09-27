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
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return true;
        nums.emplace_back(INT_MAX);

        bool modified = false;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1])
            {
                if (modified)
                    return false;
                if (i && (nums[i + 1] < nums[i - 1]))
                    nums[i + 1] = nums[i];
                else
                    nums[i] = nums[i + 1];
                modified = true;
            }
        return true;
    }
};