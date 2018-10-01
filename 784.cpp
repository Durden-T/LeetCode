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
    vector<string> ans;

  public:
    vector<string> letterCasePermutation(string S)
    {
        helper(S, 0, "");
        return ans;
    }

  private:
    void helper(string S, int i, string path)
    {
        if (i == S.size())
        {
            ans.push_back(path);
            return;
        }
        helper(S, i + 1, path + S[i]);
        if (isalpha(S[i]))
            helper(S, i + 1, islower(S[i]) ? path + (char)toupper(S[i]) : path + (char)tolower(S[i]));
    }
};