/*************************************************************************
	> File Name: 144.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 09:03:01 2021
 ************************************************************************/

#include<iostream>
#include <vector>
#include <queue>
#include <stack>

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
	
    vector<int> preorderTraversal(TreeNode* root) {
		// // 1. 递归
		// vector<int> res;
		// preorder(root, res);
		// return res;

		// 2. 迭代
		vector<int> res;
		stack<TreeNode *> stk;
		while(root != nullptr || !stk.empty()) {
			while(root != nullptr) {
				res.push_back(root->val);
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			root = root->right;
		}
		return res;
    }
	void preorder(TreeNode *root, vector<int>& res) {
		if(root != nullptr) {
			res.push_back(root->val);
			preorder(root->left, res);
			preorder(root->right, res);
		}
	}
	TreeNode* buildTree(vector<int>& nums) {
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
			if(nums[i++] != 0) {
				p->right = new TreeNode(nums[i-1]);
				que.push(p->right);
			}
		}
		return root;
	}
};

int main() {
	vector<int> nums = {1,0,2,3};

	Solution  solution;
	TreeNode *root = solution.buildTree(nums);
	vector<int> res = solution.preorderTraversal(root);
	cout << "res: " << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}