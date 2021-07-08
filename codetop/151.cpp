/*************************************************************************
	> File Name: 151.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 00:36:54 2021
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		stack<string> stk;
		string tmp = "", ans = "";
		for (int i = 0; i < s.length(); i++) {
			if(s[i] != ' ') {
				tmp = tmp + s[i];
				if(i == s.length()-1 && tmp != "") {
					stk.push(tmp);
				}
			}
			else {
				cout << "tmp: " << tmp << endl;
				stk.push(tmp);
				tmp = "";
			}
		}
		while(!stk.empty()) {
			ans = ans + " " + stk.top();
			stk.pop();
		}
		ans = ans.substr(1, ans.length()-1);
		return ans;
    }
};

int main() {
	string s = "the sky is blue";

	Solution solution;
	string res = solution.reverseWords(s);
	cout << "res: " << res << endl;
}