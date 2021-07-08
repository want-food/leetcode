#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        if(m == 0 || m < n) return {};
        vector<int> res;
        vector<int> pattern(26, 0);
        for (char ch: p) {
            pattern[ch - 'a']++;
        }
        vector<int> vec(26, 0);
        for (int i = 0; i < n-1; i++) {
            vec[s[i] - 'a']++;
        }
        for (int i = n-1; i < m; i++) {
            vec[s[i] - 'a']++;
            if(i != n-1) {
                vec[s[i-n] - 'a']--;
            }
            if(vec == pattern) {
                res.push_back(i-n+1);
            }
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd", p = "abc";

    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    cout << "res: " << endl;
    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
}