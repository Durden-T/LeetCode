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
    int lengthLongestPath(string input)
    {
        int choose = 3;
        if (choose == 0)
        {
            string s = '\n' + input;
            unordered_map<int, int> dic;
            dic.emplace(0, -1);
            bool file;
            int pos = 0, ans = 0;
            while (pos < s.size())
            {
                file = false;
                int level = 1;
                while (++pos < s.size() && s[pos] == '\t')
                    ++level;
                int size = 0;
                while (pos < s.size() && s[pos] != '\n')
                {
                    if (s[pos] == '.')
                        file = true;
                    ++pos;
                    ++size;
                }
                if (file)
                    ans = max(ans, dic[level - 1] + size + 1);
                else
                    dic[level] = dic[level - 1] + size + 1;
            }
            return ans;
        }


        else if (choose == 1)
        {
            input += '\n';
            int n = input.size();
            unordered_map<int, int> dic;
            dic[-1] = 0;
            int size = 0, level = 0, ans = 0;
            bool is_file = false;

            for (int i = 0; i < n; ++i)
            {
                switch (input[i])
                {
                case '\n':
                    if (is_file)
                        ans = max(ans, size + dic[level - 1]);
                    else
                        dic[level] = size + dic[level - 1] + 1; // include slash
                    level = 0;
                    size = 0;
                    is_file = false;
                    break;

                case '\t':
                    ++level;
                    break;

                case '.':
                    is_file = true;
                    ++size;
                    break;

                default:
                    ++size;
                }
            }
            return ans;
        }


        else if (choose == 2)
        {
            stringstream ss(input);
            stack<int> parentLen; // path size of parent folders to current entry
            int level, ans = 0;   // level, size of longest file path
            for (string s; getline(ss, s, '\n');)
            {
                int curLen = s.size() - (level = s.rfind('\t') + 1); // size and level of current entry
                while (parentLen.size() > level)
                    parentLen.pop(); // find size of parent directory
                if (!parentLen.empty())
                    curLen += 1 + parentLen.top(); // attach parent path, 1 for '\'
                if (s.rfind('.') < s.size())
                    ans = max(ans, curLen); // update path size if file
                else
                    parentLen.push(curLen); // record current entry path size if directory
            }
            return ans;
        }


        else if (choose == 3)
        {
            int level, ans = 0;
            stringstream ss(input);
            unordered_map<int, int> dic;
            for (string s; getline(ss, s, '\n');
                 ans = max(ans, (s.find('.') < s.size()) * dic[level + 1] - 1))
                dic[(level = s.rfind('\t') + 1) + 1] = dic[level] + s.size() - level + 1;
            return ans;
        }
    }
};