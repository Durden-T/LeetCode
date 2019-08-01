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
	int getSum(int a, int b) 
	{
		int sum = a;

		while (b)
		{
			sum = a ^ b;//calculate sum of a and b without thinking the carry 
			b = unsigned(a & b) << 1;//calculate the carry
			a = sum;//add sum(without carry) and carry
		}

		return sum;
	}
};