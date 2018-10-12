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
    bool isValidSerialization(string preorder)
    {
        int choose = 1;
        if (choose == 0)
        {
            stack<string> s;
            stringstream ss(preorder);
            string t;
            while (getline(ss, t, ','))
            {
                if (t != "#")
                    s.push(t);
                else
                {
                    while (!s.empty() && s.top() == "#")
                    {
                        s.pop();
                        if (s.empty())
                            return false;
                        s.pop();
                    }
                    s.push("#");
                }
            }
            return s.size() == 1 && s.top() == "#";
        }

        else if (choose == 1)
        {
            if (preorder.empty())
                return false;
            preorder += ',';
            int capacity = 1;
            for (int i = 0; i < preorder.size(); ++i)
                if (preorder[i] == ',')
                {
                    if (--capacity < 0)
                        return false;
                    if (preorder[i - 1] != '#')
                        capacity += 2;
                }
            return !capacity;
        }
    }
};