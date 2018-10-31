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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    int eraseOverlapIntervals(vector<Interval> &intervals)
    {
        if (intervals.size() < 2)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });
        int ans = 0;
        auto last = &intervals.front();
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start != last->start && intervals[i].start >= last->end)
                last = &intervals[i];
            else
            {
                ++ans;
                if (last->end > intervals[i].end)
                    last = &intervals[i];
            }
        }
        return ans;
    }
};