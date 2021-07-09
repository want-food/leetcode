/*************************************************************************
	> File Name: 113.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Wed Jul  7 09:03:55 2021
 ************************************************************************/

#include<iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> ans;
		vector<int> vec;
		dfs(root, targetSum, 0, vec, ans);
		return ans;
    }
	void dfs(TreeNode *root, int targetSum, int sum, vector<int>& vec, vector<vector<int>>& ans) {
		if(root == nullptr) return;
		sum += root->val;
		vec.push_back(root->val);
		if(root->left == nullptr && root->right == nullptr) {
			if(sum == targetSum) {
				ans.push_back(vec);
			}
			vec.pop_back();
			return;
		}
		dfs(root->left, targetSum, sum, vec, ans);
		dfs(root->right, targetSum, sum, vec, ans);
		vec.pop_back();
	}
	TreeNode *buildTree(vector<int>& nums)  {
		if(nums.size() == 0) return nullptr;

		TreeNode *root = new TreeNode(nums[0]);
		queue<TreeNode*> que;
		que.push(root);
		for (int i = 1; i < nums.size(); ) {
			TreeNode *p = que.front();
			que.pop();
			if(nums[i++] != 0) {
				p->left = new TreeNode(nums[i-1]);
				que.push(p->left);
			}
			if(nums[i++] !=  0) {
				p->right = new TreeNode(nums[i-1]);
				que.push(p->right);
			}
		}
		return root;
	}
};

int main() {
	vector<int> nums = {5,4,8,11,0,13,4,7,2,0,0,5,1};
	int targetSum = 22;
	// nums = {1,2};targetSum = 0;

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	vector<vector<int>> res = solution.pathSum(root, targetSum);
	cout << "res: " << endl;
	for (vector<int>& vec: res) {
		for (int i: vec) {
			cout << i <<  " ";
		}
		cout << endl;
	}
	cout << endl;
}