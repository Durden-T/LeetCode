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
    string toGoatLatin(string S)
    {
        vector<bool> isVowel(26, false);

        for (char c : {'a', 'e', 'i', 'o', 'u'})
            isVowel[c - 'a'] = true;

        stringstream ss(S);
        string token;
        string result;
        int i = 0;
        while (ss >> token)
        {
            ++i;
            string word;
            if (isVowel[tolower(token[0]) - 'a'])
                word = token;
            else
            {
                word = token.substr(1);
                word += token[0];
            }
            word += "ma";
            word.append(i, 'a');
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};