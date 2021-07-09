/*************************************************************************
	> File Name: 199.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 22:54:56 2021
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
	vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
		dfs(root, 0);
		return ans;
    }
	void dfs(TreeNode *root, int depth) {
		if(root->left == nullptr || root->right == nullptr) {
			
		}
	}
	TreeNode *buildTree(vector<int>& nums) {
		if(nums.size() == 0) return nullptr; 

		TreeNode *root = new TreeNode(nums[0]);
		queue<TreeNode*> que;
		que.push(root);
		for (int i = 1; i < nums.size();  ) {
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
	vector<int> nums = {1,2,3,0,5,0,4};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	vector<int> res = solution.rightSideView(root);
	cout << "res: " << endl;
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
}