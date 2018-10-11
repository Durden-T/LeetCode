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

void helper(vector<pair<int, int>> &s, vector<pair<int, int>> path, int pos, vector<vector<pair<int, int>>> &all)
{
    if (pos == s.size())
    {
        all.push_back(path);
        return;
    }
    helper(s, path, pos + 1, all);
    path.push_back(s[pos]);
    helper(s, path, pos + 1, all);
}

int main()
{
    //vector<pair<int, int>> s{{0,0}};
    //vector<pair<int, int>> s{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<pair<int, int>> s{{0, 0}, {0, 1}, {0,2},{1, 0}, {1, 1},{1,2},{2,0},{2,1},{2,2}};
    vector<vector<pair<int, int>>> all, ans;
    helper(s, {}, 0, all);
    //all.push_back({{0, 1}, {1, 1}});
    for (auto &v : all)
    {
        for (int i = 0; i < v.size(); ++i)
            for (int j = 0; j < v.size(); ++j)
                if (v[i].second == v[j].first)
                {
                    pair<int, int> t={v[i].first, v[j].second};
                    if (find(v.begin(), v.end(), t) == v.end())
                        goto end;
                }
        ans.push_back(v);
    end:;
    }
    cout << ans.size() << endl;
    getchar();
    getchar();
    getchar();
    return 0;
}