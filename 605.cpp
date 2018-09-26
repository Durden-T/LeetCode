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

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size() - 1 && n; ++i)
        {
            if (flowerbed[i])
                continue;
            if (!i && !flowerbed[1])
            {
                --n;
                flowerbed[0] = 1;
            }
            else if (!flowerbed[i - 1] && !flowerbed[i + 1])
            {
                --n;
                flowerbed[i] = 1;
            }
        }
        if (!n)
            return true;
        return (!flowerbed.back() && !flowerbed[flowerbed.size() - 2]) ? !(n - 1) : false;
    }
};