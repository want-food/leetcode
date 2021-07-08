#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });

        int n = people.size();
        vector<vector<int>> res(n);
        for (const vector<int>& vec: people) {
            int pos = vec[1] + 1;
            for (int j = 0; j < n; j++) {
                if(res[j].empty()) {
                    pos--;
                    if(pos == 0) {
                        res[j] = vec;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> people = {{7,0}, {4,4},{7,1},{5,0},{6,1},{5,2}};

    Solution solution;
    vector<vector<int>> res = solution.reconstructQueue(people);
    cout << "res: " << endl;
    for (vector<int>& vec: res) {
        cout << vec[0] << " " << vec[1] << endl;
    }
    cout << endl;
}