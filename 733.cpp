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
    int color = -1;
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (color == -1)
            color = image[sr][sc];
        if ( sr == -1 || sr == image.size() || sc == -1 || sc == image[0].size() || image[sr][sc] != color || color == newColor)
            return image;
        image[sr][sc] = newColor;
        floodFill(image, sr - 1, sc, newColor);
        floodFill(image, sr + 1, sc, newColor);
        floodFill(image, sr, sc - 1, newColor);
        floodFill(image, sr, sc + 1, newColor);
        return image;
    }
};