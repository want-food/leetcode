/*************************************************************************
	> File Name: 543.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Wed Jul  7 09:43:04 2021
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
    int diameterOfBinaryTree(TreeNode* root) {
		if(root == nullptr) return 0;
		int ans = 0;
		diameterOfSingleTree(root, ans);
		if(ans == 0) return 0;
		return ans-1;
    }
	int diameterOfSingleTree(TreeNode* root, int& ans) {
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) return 1;

		int l = diameterOfSingleTree(root->left, ans);
		int r = diameterOfSingleTree(root->right, ans);
		if(ans < l+r+1) ans = l+r+1;
		return 1 + max(l, r);
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
	vector<int> nums = {1,2,3,4,5};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	int res = solution.diameterOfBinaryTree(root);
	cout << "res: " << res << endl;
}