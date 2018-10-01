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
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int choose = 1;
        if(choose==0)
        {
            return !(rec1[2] <= rec2[0] || // left
                     rec1[3] <= rec2[1] || // bottom
                     rec1[0] >= rec2[2] || // right
                     rec1[1] >= rec2[3]);  // top
        }
        else if(choose==1)
        {
            return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && // width > 0
                    min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));  // height > 0
        }
    }
};
