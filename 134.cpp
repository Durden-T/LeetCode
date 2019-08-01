#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include<vector>
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

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution 
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{

		int sum = 0, start_idx = 0, min_sum = INT_MAX;

		for (int i = 0; i < gas.size(); ++i)
		{
			sum += gas[i] - cost[i]; //circuit exists iff sum(net gas) >= 0
			if (sum < min_sum)
			{                  //if running sum is lowest, record next index as start
				min_sum = sum; //IDEA: we want smallest running sum @ end of circuit
				start_idx = (i + 1) % gas.size();
			}
		}
		if (sum < 0) //total sum < 0 : not enough total gas to traverse circuit
			return -1;
		else
			return start_idx;
	}
};