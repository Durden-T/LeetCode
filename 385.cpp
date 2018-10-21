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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The ans is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The ans is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution
{

  public:
    NestedInteger deserialize(const string s)
    {
        int choose = 2;
        if (choose == 0)
        {
            int pos = 0; //pos ALWAYS points to 1 position past the last parsed string;
                         //This is an invariance maintained across the entire program.
            return parse(s, pos);
        }


        else if (choose == 1)
        {
            istringstream in(s);
            return deserialize(in);
        }


        else if (choose == 2)
        {
            auto isnumber = [](char c) { return c == '-' || isdigit(c); };

            stack<NestedInteger> stk;
            stk.push(NestedInteger());

            for (auto it = s.begin(); it != s.end();)
            {
                const char c = *it;
                if (isnumber(c))
                {
                    auto it2 = find_if_not(it, s.end(), isnumber);
                    int val = stoi(string(it, it2));
                    stk.top().add(NestedInteger(val));
                    it = it2;
                }
                else
                {
                    if (c == '[')
                        stk.push(NestedInteger());
                    else if (c == ']')
                    {
                        NestedInteger ni = stk.top();
                        stk.pop();
                        stk.top().add(ni);
                    }
                    ++it;
                }
            }

            NestedInteger ans = stk.top().getList().front();
            return ans;
        }
    }

  private:
    NestedInteger parse(const string &s, int &pos) //0
    {
        if (s[pos] == '[')
            return parseList(s, pos);
        return parseNum(s, pos);
    }
    NestedInteger parseNum(const string &s, int &pos)
    {
        int num = 0;
        int sign = 1;
        if (s[pos] == '-')
        {
            sign = -1;
            ++pos;
        }
        while (pos < s.size() && s[pos] != ']' && s[pos] != ',')
            num = num * 10 + s[pos++] - '0';
        return NestedInteger(sign * num);
    }
    NestedInteger parseList(const string &s, int &pos)
    {
        NestedInteger ni;
        while (s[pos] != ']')
        {
            ++pos; //skip [ or ,
            if (s[pos] == ']')
                break; //handle [] or [1,2,]
            ni.add(parse(s, pos));
        }
        ++pos; // skip ]
        return ni;
    }

    NestedInteger deserialize(istringstream &in) //1
    {
        int number;
        if (in >> number)
            return NestedInteger(number);
        in.clear();
        in.get();
        NestedInteger list;
        while (in.peek() != ']')
        {
            list.add(deserialize(in));
            if (in.peek() == ',')
                in.get();
        }
        in.get();
        return list;
    }
};
