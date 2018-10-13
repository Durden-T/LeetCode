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
    bool increasingTriplet(vector<int> &nums)
    {
        int choose = 0;
        if (choose == 0)
        {
            int len = nums.size();
            if (len < 3)
                return false;
            vector<int> vleftmin = nums;
            int left_min = nums[0];
            for (int i = 1; i < len; i++)
            {
                vleftmin[i] = min(vleftmin[i - 1], nums[i - 1]);
            }
            int right_max = nums.back();
            for (int i = len - 2; i >= 0; i--)
            {
                if (nums[i] > vleftmin[i] && nums[i] < right_max)
                {
                    //cout << "i found" << i << endl;
                    return true;
                }
                right_max = max(right_max, nums[i]);
            }
            return false;
        }
        else if (choose == 1)
        {
            int c1 = INT_MAX, c2 = INT_MAX;
            for (int x : nums)
                if (x <= c1)
                    c1 = x;       // c1 is min seen so far (it's a candidate for 1st element)
                else if (x <= c2) // here when x > c1, i.e. x might be either c2 or c3
                    c2 = x;       // x is better than the current c2, store it
                else              // here when we have/had c1 < c2 already and x > c2
                    return true;  // the increasing subsequence of 3 elements exists
            return false;
        }
    }
};