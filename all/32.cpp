/*************************************************************************
	> File Name: 32.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Wed May 26 23:22:05 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		stack<char> stk;
		string r = "";
		int res = 0;

		for (char& ch: s) {
			if(ch == '(' || ch == '[' || ch == '{') {
				stk.push(ch);
				continue;
			}
			if(stk.size() == 0) {
				if(res < r.length()) 
					res = r.length();
				r = "";
				continue;
			}
			char top = stk.top();
			stk.pop();
			if((ch == ')' && top != '(') || (ch == ']' && ch != '[') || (ch == '}' && top != '{')) {
				if(res < r.length()) 
					res = r.length();
				r = "";
				toempty(stk);
				continue;
			}
			r = top + r + ch;
		}
		if(res < r.length())
			return r.length();
		return res;
	}
	void toempty(stack<char>& stk) {
		while(stk.empty() == false) {
			stk.pop();
		}
	}
};

int main() {
	string s = "()(()";

	Solution solution;
	int res = solution.longestValidParentheses(s);
	cout << "res: " << endl;
	cout << res << endl;
}