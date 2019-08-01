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
#include <ctime>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(0); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(0);              // untie cin & cout
    cout.tie(0);
    return 0;
}();

class Solution
{
  public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        sort(times.begin(), times.end());
        vector<int> distance(N + 1, INT_MAX);
        distance[K] = 0;
    }
};

void dijkstra(Graph &G, int start, vector<int> &len, vector<int> &path)
{
    len[start] = 0;
    auto cmp = [&len](const int a, const int b) { 
        return len[a] > len[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> PQ;
    PQ.push(start);
    while (!PQ.empty())
    {
        int t = PQ.top();
        PQ.pop();
        for (auto e : G[t]->to)
            if (len[e->end] > len[t] + e->weight)
            {
                len[e->end] = len[t] + e->weight;
                path[e->end] = t;
                PQ.push(e->end);
            }
    }
}