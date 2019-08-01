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
	string reverseOnlyLetters(string S) 
	{
		auto i = S.begin(), j = S.end()-1;
		while (i < j)
		{
			if (!isalpha(*i))
				++i;
			else if (!isalpha(*j))
				--j;
			else
				swap(*i++, *j--);
		}
		return S;
	}
};