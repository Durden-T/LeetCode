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
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))
            return -1;
        unordered_set<string> bset, eset, *set1, *set2;
        bset.insert(start), eset.insert(end);
        int step = 0, n = start.size();
        while (!bset.empty() and !eset.empty())
        {
            if (bset.size() <= eset.size())
                set1 = &bset, set2 = &eset;
            else
                set2 = &bset, set1 = &eset;
            unordered_set<string> tmp;
            step++;
            for (auto itr = set1->begin(); itr != set1->end(); ++itr)
            {
                for (int i = 0; i < n; ++i)
                {
                    string dna = *itr;
                    for (auto g : string("ATGC"))
                    {
                        dna[i] = g;
                        if (set2->count(dna))
                            return step;
                        if (dict.count(dna))
                        {
                            tmp.insert(dna);
                            dict.erase(dna);
                        }
                    }
                }
            }
            *set1 = tmp;
        }
        return -1;
    }
};