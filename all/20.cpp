/*************************************************************************
	> File Name: 20.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 09:23:54 2021
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
		for (const char& ch: s) {
			if(ch == '(' || ch == '{' || ch == '[') {
				stk.push(ch);
				continue;
			}
			if(stk.size() == 0)
				return false;
			char tmp = stk.top();
			stk.pop();
			if(tmp == '(' && ch != ')') {
				return false;
			}
			if(tmp == '[' && ch != ']') {
				return false;
			}
			if(tmp == '{' && ch != '}') {
				return false;
			}
		}
		if(stk.size() != 0)
			return false;
		return true;
	}
};

int main() {
	string s = "((([)))]";

	Solution solution;
	bool res = solution.isValid(s);
	cout << "res: " << res << endl;
}