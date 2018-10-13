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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int choose = 3;
        if (choose == 0)
        {
            unordered_map<int, int> map;
            vector<int> ans(k);
            for (int i : nums)
                ++map[i];
            vector<pair<int, int>> t(map.begin(), map.end());
            sort(t.begin(), t.end(), [](pair<int, int> &a, pair<int, int> &b) {
                return a.second > b.second;
            });
            for (int i = 0; i < k; ++i)
                ans[i] = t[i].first;
            return ans;
        }
        else if (choose == 1)
        {
            unordered_map<int, int> map;
            for (int num : nums)
                ++map[num];
            vector<int> ans;
            /** use the priority queue, like the max-heap , we will keep (size-k) smallest elements in the queue**/
            /** pair<first, second>: first is frequency,  second is number **/
            priority_queue<pair<int, int>> pq;
            for (auto it = map.begin(); it != map.end(); ++it)
            {
                pq.push(make_pair(it->second, it->first));
                /** onece the size bigger than size-k, we will pop the value, which is the top k frequent element value **/
                if (pq.size() > (int)map.size() - k)
                {
                    ans.push_back(pq.top().second);
                    pq.pop();
                }
            }
            return ans;
        }
        else if (choose == 2)
        {
            unordered_map<int, int> map;
            vector<vector<int>> bucket(nums.size() + 1);
            vector<int> ans(k);
            for (int i : nums)
                ++map[i];
            for (auto &p : map)
                bucket[p.second].push_back(p.first);
            for (int i = nums.size(), j = 0; i && j < k; --i)
                if (!bucket[i].empty())
                    for (int a : bucket[i])
                    {
                        ans[j++] = a;
                        if (j == k)
                            break;
                    }
            return ans;
        }
        else if (choose == 3)
        {
            vector<int> ans(k);
            unordered_map<int, int> map;

            for (int i : nums)
                ++map[i];
            vector<pair<int, int>> t(map.begin(), map.end());

            nth_element(t.begin(), t.begin() + k, t.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });

            for (int i = 0; i < k; ++i)
                ans[i] = t[i].first;
            return ans;
        }
    }
};