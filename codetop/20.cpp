/*************************************************************************
	> File Name: 20.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 23:45:58 2021
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
		for (char ch: s) {
			if(ch == '(' || ch == '[' || ch == '{') {
				stk.push(ch);
				continue;
			}
			if(stk.empty()) return false;
			char c = stk.top();
			stk.pop();
			if(c == '(' && ch != ')') return false;
			if(c == '[' && ch != ']') return false;
			if(c == '{' && ch != '}') return false;
		}
		if(stk.empty()) return true;
		return false;
    }
};

int main() {
	string s = "[(())]";

	Solution solution;
	bool res = solution.isValid(s);
	cout << "res: " << res << endl;
}