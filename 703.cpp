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

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> p;

  public:
    KthLargest(int k, vector<int> nums) : k(k)
    {
        for (int i : nums)
            p.push(i);
        while (p.size() > k)
            p.pop();
    }

    int add(int val)
    {
        p.push(val);
        if (p.size() > k)
            return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */