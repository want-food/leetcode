/*************************************************************************
	> File Name: 3.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 00:29:28 2021
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int left = 0, ans = 0, len = s.length();
		for (int i = 0; i < len; i++) {
			auto it = map.find(s[i]);
			if(it == map.end() || map[s[i]] < left) {
				map[s[i]] = i;
				if(i == len - 1 && ans < i - left + 1) {
					return i - left + 1;
				}
			}
			else {
				if(ans < i - left) ans = i - left;
				left = map[s[i]] + 1;
				map[s[i]] = i;
			}
		}
		return ans;
    }
};

int main() {
	string s = "asd";

	Solution solution;
	int res = solution.lengthOfLongestSubstring(s);
	cout << "res: " << res << endl;
}