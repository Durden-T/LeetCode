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
    vector<int> findRightInterval(vector<Interval> &intervals)
    {
        int choose = 2;
        if (choose == 0)
        {
            int len = intervals.size();
            vector<pair<Interval, int>> pairs(len);
            for (int i = 0; i < len; ++i)
                pairs[i] = {intervals[i], i};
            auto comp = [](const pair<Interval, int> &l, const pair<Interval, int> &r) -> bool {
                return l.first.start < r.first.start;
            };
            sort(pairs.begin(), pairs.end(), comp);
            vector<int> ans(len, -1);
            for (int i = 0; i < len - 1; ++i)
            {
                int target = pairs[i].first.end;
                int left = i + 1, right = len - 1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    int start = pairs[mid].first.start;
                    if (start == target)
                    {
                        left = mid;
                        break;
                    }
                    else if (start < target)
                    {
                        left = mid + 1;
                    }
                    else if (left == right)
                    {
                        if (pairs[mid].first.start < pairs[i].first.end)
                        {
                            left = len;
                        }
                        break;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                ans[pairs[i].second] = left == len ? -1 : pairs[left].second;
            }
            return ans;
        }

        else if (choose == 1)
        {
            int n = intervals.size();
            int max_st = INT_MIN;
            unordered_map<int, int> table;
            for (int i = 0; i < n; ++i)
            {
                table[intervals[i].start] = i;
                max_st = max(max_st, intervals[i].start);
            }
            vector<int> ans;
            for (auto i : intervals)
            {
                if (i.end > max_st)
                {
                    ans.emplace_back(-1);
                }
                else
                {
                    int j;
                    for (j = i.end; !table.count(j); ++j)
                        ;
                    ans.emplace_back(table[j]);
                }
            }
            return ans;
        }

        else if (choose == 2)
        {
            map<int, int> Map;
            vector<int> ans(intervals.size(), -1);
            for (int i = 0; i < intervals.size(); ++i)
                Map[intervals[i].start] = i;
            for (int i = 0; i < intervals.size(); ++i)
            {
                auto itr = Map.lower_bound(intervals[i].end);
                if (itr != Map.end())
                    ans[i] = itr->second;
            }
            return ans;
        }
    }
};