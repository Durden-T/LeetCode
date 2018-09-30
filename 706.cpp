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

class MyHashMap
{
  public:
  private:
    int elements[1000001];

  public:
    MyHashMap()
    {
        fill_n(elements, 1000001, -1);
    }

    void put(int key, int value)
    {
        elements[key] = value;
    }

    int get(int key)
    {
        return elements[key];
    }

    void remove(int key)
    {
        elements[key] = -1;
    }
};