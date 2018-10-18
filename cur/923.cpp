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

//2.60
unsigned replace_byte(unsigned x, int i, unsigned char b)
{

    x &= ~(0xff << (i * 8));
    x |= b << (i * 8);
    return x;
}
//2.65
int odd_ones(unsigned x)
{
    /*size_t count = 0;
    ......
    return count & 1;*/
    int ans = 0;
    while (x)
    {
        ++ans;
        x &= x - 1;
    }
    return ans;
}

//2.67 b
int int_size_is_32(void)
{
    int set_msb = 1 << 31, beyond_msb = set_msb * 2;
    return set_msb && !beyond_msb;
}

//2.67 c
/*int int_size_is_32(void)
{
    int set_msb = 1 << 15, beyond_msb = set_msb * 2, s = (beyond_msb >> 1) * beyond_msb, b = s * 2;
    return set_msb && beyond_msb && s && !b;
}*/

//2.68 hehe
int lower_one_mask(int n)
{
    const int w = sizeof(int) * 8;
    int ans = INT_MAX;
    n != w && (ans = INT_MAX >> (w - n - 1));
    return ans;
}
int main()
{
    cout << hex << lower_one_mask(1);
    getchar();
    getchar();
    return 0;
}