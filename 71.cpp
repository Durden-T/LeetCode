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
	string simplifyPath(string path)
	{
		int choose = 0;
		if (choose == 0)
		{
			path += '/';
			vector<string> ans;
			int i = 0;
			while (path[++i] == '/')
				;
			int last = i;
			while ((i = path.find('/', i)) != string::npos)
			{
				string t = path.substr(last, i - last);
				if (t == "..")
				{
					if (!ans.empty())
						ans.pop_back();
				}
				else if (t != ".")
					ans.emplace_back(move(t));
				while (path[++i] == '/')
					;
				last = i;
			}
			string t;
			for (string& s : ans)
				t.append('/' + s);
			return t.empty() ? "/" : t;
		}
		else if (choose == 1)
		{
			vector<string> folder_stack;
			stringstream ss{ path };
			string tmp;
			while (getline(ss, tmp, '/'))
				if (tmp.empty() || "." == tmp)
					continue;
				else if (".." == tmp && !folder_stack.empty())
					folder_stack.pop_back();
				else if (".." != tmp)
					folder_stack.push_back(move(tmp));
			string res;
			for (auto& f : folder_stack)
				res += "/" + f;
			return res.empty() ? "/" : res;
		}
	}
};