/*************************************************************************
	> File Name: 110.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 01:13:01 2021
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
    bool isBalanced(TreeNode* root) {
		int r = dfs(root);
		if(r == -1) return false;
		return true;
    }
	int dfs(TreeNode *root) {
		if(root == nullptr) return 0;
		int l = dfs(root->left);
		int r = dfs(root->right);
		if(l == -1 || r == -1) return -1;
		int t = l-r;
		if(t == -1 || t == 1 || t == 0) return max(l, r) + 1;
		return -1;
	}
	TreeNode *buildTree(vector<int>& nums) {
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
	bool res = solution.isBalanced(root);
	cout << "res: " << res << endl;
}