/*************************************************************************
	> File Name: 22.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 09:46:07 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string r = "";
        vector<string> res;
        int len = n * 2;
		dfs(res, n, r, 0);
		return res;
    }
    void dfs(vector<string>& res, int& n, string& r, int num) {
		// num: 保存的是左括号的个数
		// 右括号的个数为： r.length() - num
        if(r.length() == n * 2) {
            res.push_back(r);
            return ;
        }
		if(num < n) {
			r.push_back('(');
			dfs(res, n, r, num+1);
			r.pop_back();
		}
		if(num * 2 > r.length()) {
			r.push_back(')');
			dfs(res, n, r, num);
			r.pop_back();
		}
		else
			return;
	}
};

int main() {
	int n;
	cin >> n;

	Solution solution;
	vector<string> res = solution.generateParenthesis(n);
	for (string& s: res) {
		cout << s << endl;
	}
}