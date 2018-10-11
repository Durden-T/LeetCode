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
    int maxProduct(vector<string> &words)
    {
        int choose = 2;
        if (choose == 0)
        {
            if (words.size() < 2)
                return 0;
            vector<bitset<26>> map(words.size());
            bitset<26> flag;
            int ans = 0;
            for (int i = 0; i < words.size(); ++i)
            {
                for (int c : words[i])
                    map[i][c - 'a'] = 1;
                for (int j = 0; j < i; ++j)
                    if ((map[i] & map[j]) == flag && words[i].size() * words[j].size() > ans)
                        ans = words[i].size() * words[j].size();
            }
            return ans;
        }
        else if (choose == 1)
        {
            if (words.size() < 2)
                return 0;
            int wordBits[words.size()] = {};
            int ans = 0;

            for (int i = 0; i < words.size(); ++i)
            {
                for (int c : words[i])
                    wordBits[i] |= (1 << (c - 'a'));
                for (int j = 0; j < i; ++j)
                    if (!(wordBits[j] & wordBits[i]) && words[i].size() * words[j].size() > ans)
                        ans = words[i].size() * words[j].size();
            }
            return ans;
        }
        else if (choose == 2)
        {
            int ans = 0;
            unordered_map<int, int> M;
            for (int i = 0; i < words.size(); ++i)
            {
                int v = 0;
                for (int c : words[i])
                    v |= 1 << (c - 'a' + 1);
                auto it = M.find(v);
                if (it == M.end())
                    M[v] = words[i].size();
                else if (it->second < words[i].size())
                    it->second = words[i].size();
            }
            for (auto it = M.begin(); it != M.end(); ++it)
            {
                auto ip = it;
                for (++ip; ip != M.end(); ++ip)
                    if (!(it->first & ip->first) && it->second * ip->second > ans)
                        ans = it->second * ip->second;
            }
            return ans;
        }
    }
};