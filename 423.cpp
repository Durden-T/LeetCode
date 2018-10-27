#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ans>
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
    string originalDigits(string s)
    {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<char> nums = {'0', '2', '4', '6', '8', '1', '3', '5', '7', '9'};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        int counts[26] = {};
        string ans;
        for (int ch : s)
            ++counts[ch - 'a'];

        for (int i = 0; i < 10; ++i)
        {
            int count = counts[distinct_char[i] - 'a'];
            for (int j = 0; j < words[i].size(); ++j)
                counts[words[i][j] - 'a'] -= count;
            ans += string(count, nums[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};