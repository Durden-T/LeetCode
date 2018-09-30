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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, int> idMap;

        for (int i = 0; i < employees.size(); i++)
            idMap[employees[i]->id] = i;

        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty())
        {
            int uid = q.front();
            q.pop();
            res += employees[idMap[uid]]->importance;
            for (auto sid : employees[idMap[uid]]->subordinates)
                q.push(sid);
        }
        return res;
    }
};