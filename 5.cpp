/*************************************************************************
	> File Name: 5.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 09:51:34 2021
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int maxLen = 0, len = s.length(), l = 0;
		string ans = "";

		for (int i = 0; i < len; i++) {
			int left = i, right = i;
			while (left >= 0 && right < len) {
				if(s[left] == s[right]) {
					left--, right++;
				}
				else break;
			}
			if(maxLen < right-left-1) {
				maxLen = right-left-1;
				ans = s.substr(left+1, right-left-1);
			}
			
			if(i == s.length()-1) break;
			left = i, right = i+1;
			while (left >= 0 && right < len) {
				if(s[left] == s[right]) {
					left--, right++;
				}
				else break;
			}
			if(maxLen < right-left-1) {
				maxLen = right-left-1;
				ans = s.substr(left+1, right-left-1);
			}
		}
		return ans;
    }
};

int main() {
	string s = "a";

	Solution solution;
	string res = solution.longestPalindrome(s);
	cout << "res: " << res << endl;
}