#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include<vector>
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

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();


class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& p)
	{
		vector<int> ans;
		vector<int> inDegree(numCourses, 0);
		vector<vector<int>> graph(numCourses);
		for (auto& v : p)
		{
			graph[v[1]].emplace_back(move(v[0]));
			++inDegree[v[0]];
		}
		queue<int> Q;
		for (int i = 0; i < numCourses; ++i)
			if (!inDegree[i])
				Q.push(i);
		int count = 0;
		while (!Q.empty())
		{
			int t = Q.front();
			Q.pop();
			--numCourses;
			ans.emplace_back(move(t));
			for (int to : graph[t])
				if (--inDegree[to] == 0)
					Q.push(to);
		}
		return numCourses == 0 ? ans : vector<int>();
	}
};