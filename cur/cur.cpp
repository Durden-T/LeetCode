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

/*static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();*/
//1

vector<int> grayCode(int n)
{
    if (n <= 0)
        return {0};
    vector<int> ans = {0, 1};
    for (int i = 1, k = 2; i < n; i++, k <<= 1)
        for (int j = ans.size() - 1; j >= 0; j--)
            ans.emplace_back(ans[j] + k);
    return ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "n=" << n << endl;
        vector<int> t = grayCode(n);
        for (int i : t)
            cout << bitset<4>(i) << ',';
        cout << endl;
    }
}
#include <reg52.h>

sbit led1 = P2 ^ 0;
sbit led2 = P3 ^ 0;
sbit led3 = P4 ^ 0;
sbit led4 = P5 ^ 0;
sbit led5 = P6 ^ 0;
sbit led6 = P7 ^ 0;
sbit led7 = P8 ^ 0;
sbit led8 = P9 ^ 0;

void delayms(unsigned int xms) //有参函数
{
    int i，j;
    for (i = xms;
         i > 0;
         i--)
        for (j = 110; j > 0; j--)
            ;
}

void main()
{
    led1 = 0;
    delayms(1000);
    led1 = 1;

    led2 = 0;
    delayms(1000);
    led2 = 1;

    led3 = 0;
    delayms(1000);
    led3 = 1;

    led4 = 0;
    delayms(1000);
    led4 = 1;

    led5 = 0;
    delayms(1000);
    led5 = 1;

    led6 = 0;
    delayms(1000);
    led6 = 1;

    led7 = 0;
    delayms(1000);
    led7 = 1;

    led8 = 0;
    delayms(1000);
    led8 = 1;
}