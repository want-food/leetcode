/*************************************************************************
	> File Name: 17.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 08:54:32 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<vector<char>> modes = {
		{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
	vector<string> letterCombinations(string digits) {
		if(digits.length() == 0)
			return {};
		
		string comb = "";
		vector<string> res;
		dfs(res, 0, digits, comb);
		return res;
	}
	void dfs(vector<string>& res, int index, string& digits, string combination) {
		if(index == digits.length()) {
			res.push_back(combination);
			return;
		}
		int n = digits[index] - '0';
		for (const char& ch: modes[n]) {
			combination.push_back(ch);
			dfs(res, index+1, digits, combination);
			combination.pop_back();
		}
	}
};

int main() {
	string digits = "23";

	Solution solution;
	vector<string> res = solution.letterCombinations(digits);
	cout << "===res===" << endl;
	for (string& s: res) {
		cout << s << endl;
	}
}