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
	bool isInterleave(string& s1, string& s2, string& s3)
	{
		int choose = 4;
		if (choose == 0) //2d dp
		{
			if (s1.size() + s2.size() != s3.size())
				return false;
			vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
			for (int i = 0; i <= s1.size(); i++)
				for (int j = 0; j <= s2.size(); j++)
					if (!i && !j)
						dp[i][j] = true;
					else if (!i && j)
						dp[0][j] = dp[i][j - 1] && s2[j - 1] == s3[j - 1];
					else if (!j && i)
						dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
					else
						dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1] || dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
			return dp.back().back();
		}
		if (choose == 1) //1d dp
		{
			if (s1.size() + s2.size() != s3.size())
				return false;
			vector<bool> dp(s2.size() + 1, false);
			for (int i = 0; i <= s1.size(); i++)
				for (int j = 0; j <= s2.size(); j++)
					if (!i && !j)
						dp[j] = true;
					else if (!i && j)
						dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
					else if (!j && i)
						dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
					else
						dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1] || dp[j] && s1[i - 1] == s3[i + j - 1];
			return dp.back();
		}
		if (choose == 2) //simplified 1d dp
		{
			if (s1.size() + s2.size() != s3.size())
				return false;
			vector<bool> dp(s2.size() + 1, false);
			for (int i = 0; i <= s1.size(); i++)
				for (int j = 0; j <= s2.size(); j++)
					dp[j] = (!i && !j) || (i && s1[i - 1] == s3[i + j - 1] && dp[j]) || (j && s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
			return dp.back();
		}
		if (choose == 3) //dfs
		{
			if (s1.size() + s2.size() != s3.size())
				return false;
			vector<vector<bool>> invalid(s1.size() + 1, vector<bool>(s2.size() + 1, false));
			return dfs(s1, s2, s3, 0, 0, 0, invalid);
		}
		if (choose == 4) //greedy  ²»¶®
		{
			if (s1.size() + s2.size() != s3.size())
				return false;
			int i = 0, j = 0, k = 0;
			bool flag = false;
			while (k >= 0 && k < s3.size())
			{
				if (!flag && s3[k] == s1[i])
				{
					i++;
					k++;
				}
				else if (s3[k] == s2[j])
				{
					j++;
					k++;
					flag = false;
				}
				else
				{
					--i;
					--k;
					flag = true;
				}
			}
			return k == s3.size() && i == s1.size() && j == s2.size();
		}
		return true;
	}
	//choose==3
private:
	bool dfs(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<bool>>& invalid)
	{
		if (invalid[i][j])
			return false;
		if (k == s3.size())
			return true;
		bool valid = (i < s1.size() && s1[i] == s3[k] && dfs(s1, s2, s3, i + 1, j, k + 1, invalid)) || j < s2.size() && s2[j] == s3[k] && dfs(s1, s2, s3, i, j + 1, k + 1, invalid);
		if (!valid)
			invalid[i][j] = true;
		return valid;
	}
};
