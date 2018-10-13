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

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    struct cmp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first + a.second > b.first + b.second;
        }
    };

    struct comparePairs
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first + a.second < b.first + b.second;
        }
    };

  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int choose = 1;
        if (choose == 0)
        {
            if (nums1.empty() || nums2.empty())
                return {};
            vector<pair<int, int>> ans;
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            for (int i : nums1)
                for (int j : nums2)
                    pq.emplace(i, j);
            while (!pq.empty() && ans.size() < k)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            return ans;
        }

        else if (choose == 1)
        {
            if (nums1.empty() || nums2.empty())
                return {};
            priority_queue<pair<int, int>, vector<pair<int, int>>, comparePairs> pq;

            for (int i : nums1)
                for (int j : nums2)
                    if (pq.size() < k)
                        pq.emplace(i, j);
                    else if (pq.top().first + pq.top().second > i + j)
                    {
                        pq.pop();
                        pq.emplace(i, j);
                    }

            vector<pair<int, int>> ans(pq.size());
            int i = pq.size() - 1;
            while (!pq.empty())
            {
                ans[i--] = pq.top();
                pq.pop();
            }
            return ans;
        }
    }
};