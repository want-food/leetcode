/*************************************************************************
	> File Name: 207.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 14 10:35:31 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> tolearn;
	vector<int> visiting;
	vector<int> visited;
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		tolearn.resize(numCourses);
		visited.resize(numCourses);
		visiting.resize(numCourses);
		for (vector<int>& vec: prerequisites) {
			int to = vec[1], curr = vec[0];
			tolearn[curr].push_back(to);
		}
		for (int i = 0; i < numCourses; i++) {
			if(visited[i])
		}
	}
};

int main() {
	int numCourses = 2;
	vector<vector<int>> prerequisites = {{1,0},{0,1}};

	Solution solution;
	bool res = solution.canFinish(numCourses, prerequisites);
	cout << "res: " << res << endl;
}
