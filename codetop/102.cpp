/*************************************************************************
	> File Name: 102.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 22:04:46 2021
 ************************************************************************/

#include <iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		if(root == nullptr) return {{}};
		vector<vector<int>> ans;
		vector<int> vec;
		queue<TreeNode *> que;
		que.push(root);
		int count = 1;
		while(que.size() != 0) {
			TreeNode *p = que.front();
			vec.push_back(p->val);
			que.pop();
			count--;

			if(p->left) que.push(p->left);
			if(p->right) que.push(p->right);

			if(count == 0) {
				ans.push_back(vec);
				vec = {};
				count = que.size();
			}
		}
		return ans;

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
	vector<int> nums = {3,9,20,0,0,15,7};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	vector<vector<int>> res = solution.levelOrder(root);
	cout << "res: " << endl;
	for (vector<int>& vec: res) {
		for (int i: vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}