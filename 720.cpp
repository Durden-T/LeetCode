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
    struct Trie
    {
        Trie *children[26] = {nullptr};
        bool end = false;
    };

  public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        string ans;
        Trie *root = new Trie;
        for (string &word : words)
        {
            Trie *Tmp;
            if ((Tmp = startsWith(word.substr(0, word.size() - 1), root)) == nullptr)
                continue;
            if (!Tmp->children[word.back() - 'a'])
                Tmp->children[word.back() - 'a'] = new Trie;
            Tmp = Tmp->children[word.back() - 'a'];
            Tmp->end = true;
            if (word.size() > ans.size())
                ans = word;
        }
        return ans;
    }

  private:
    Trie *startsWith(string &prefix, Trie *root)
    {
        if (prefix.empty())
            return root;
        Trie *Tmp = root;
        for (int i : prefix)
        {
            if (!Tmp)
                return nullptr;
            Tmp = Tmp->children[i - 'a'];
        }
        return Tmp;
    }
};