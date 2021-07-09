/*************************************************************************
	> File Name: 56.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 09:11:05 2021
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
			return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
		});
		vector<vector<int>> res;
		int n = intervals.size(), top = 0;
		res.push_back(intervals[0]);
		for (int i = 1; i < n; i++) {
			if(intervals[i][0] > res[top][1]) {
				res.push_back(intervals[i]);
				top++;
			}
			else if(intervals[i][0] <= res[top][1] && intervals[i][1] > res[top][1]) {
				res[top][1] = intervals[i][1];
			}
		}
		return res;
    }
};

int main() {
	vector<vector<int>> intervals = {
		{1,3}, {2,6}, {8,10}, {15,18}	
	};
	intervals = {{1,4}, {4,5}};

	Solution solution;
	vector<vector<int>> res = solution.merge(intervals);
	cout << "res: " << endl;
	for (vector<int>& vec: res) {
		for (int i: vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}