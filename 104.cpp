/*************************************************************************
	> File Name: 104.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 08:55:56 2021
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
	int ans = 0;
    int maxDepth(TreeNode* root) {
		dfs(root, 1);
		return ans;
    }
	void dfs(TreeNode *root, int depth) {
		if(root == nullptr) {
			if(ans < depth-1) ans = depth-1;
			return;
		}
		dfs(root->left, depth+1);
		dfs(root->right, depth+1);
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
	TreeNode* root = solution.buildTree(nums);
	int res = solution.maxDepth(root);
	cout << "res: " << res << endl;
}