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

static int __initialSetup = []() {
	ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
	cin.tie(nullptr);            // untie cin & cout
	return 0;
}();

class Solution
{
public:
	vector<string> reorderLogFiles(vector<string>& logs)
	{
		vector <pair<string, string>> alpha;
		vector<string> digit;
		int i;
		for (string& s : logs)
		{
			i = s.find(' ') + 1;
			if (isalpha(s[i]))
				alpha.emplace_back(s.substr(i), move(s));
			else
				digit.emplace_back(move(s));
		}
		sort(alpha.begin(), alpha.end(), [](const pair<string, string> & a, const pair<string, string> & b) {
			return a.first < b.first || a.first == b.first && a.second < b.second;
			});
		vector<string> ans;
		for (auto& p : alpha)
			ans.emplace_back(p.second);
		ans.insert(ans.end(), digit.begin(), digit.end());
		return ans;
	}
};