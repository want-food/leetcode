#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // delete the ) before all (
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(') break;
            if(s[i] == ')') s.replace(i, 1, "");
        }
        cout << "s: " << s << endl;

        // get the counts of ( and )
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(') count++;
            else if(s[i] == ')') count--;
        }
        cout << "count: " << count << endl;

        vector<string> res;
        if(count > 0) removeL(s, res, 0, count, 0);
        if(count < 0) removeR(s, res, 0, count, 0);
        return res;
    }
    void removeL(string s, vector<string>& res, int index, int count, int l) {
        if(index == s.length()) {
            if(count == 0) res.push_back(s);
            return;
        } 
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                l++;
                removeL(s, res, index, count);
                string t = s.replace(index, 1, "");
                removeL(t, res, index, count-1);
            }
            else if(s[i] == ')') {
                if(l == 0) {
                    
                }
                l--;
            }
        }
    }
    void removeR(string s, vector<string>& res, int index, int count, int l) {
        if(index == s.length()) {
            if(count == 0) res.push_back(s);
            return;
        } 
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                l++;
                continue;
            }
            else if(s[i] == ')') {
                if(l > 0) {
                    removeR(s, res, index, count, l-1);
                    string t = s.replace(index, 1, "");
                    removeR(t, res, index, count-1, l);
                }
                else if(l == 0) {
                    string t = s.replace(index, 1, "");
                    removeR(t, res, index, count-1, l);
                }
            }
        }
    }
};

int main() {
    string s = ")(";

    Solution solution;
    vector<string> res = solution.removeInvalidParentheses(s);
    cout << "res: " << endl;
    for (string s: res) {
        cout << s << endl;
    }
}