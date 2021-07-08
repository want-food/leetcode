/*************************************************************************
	> File Name: 236.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 23:15:16 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
		if(root == p || root == q) return root;

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if(left != nullptr && right != nullptr) return root;
		if(left != nullptr) return left;
		if(right != nullptr) return right;
		return nullptr;
    }
	vector<TreeNode*> buildTree(vector<int>& nums, int n1, int n2) {
		if(nums.size() == 0) return {};

		vector<TreeNode*> vec;
		TreeNode *root = new TreeNode(nums[0]);
		queue<TreeNode*> que;
		que.push(root);
		if(nums[0] == n1 || nums[0] == n2) vec.push_back(root);
		for (int i = 1; i < nums.size(); ) {
			TreeNode *p = que.front();
			que.pop();

			if(nums[i++] != 0) {
				p->left = new TreeNode(nums[i-1]);
				que.push(p->left);
				if(nums[i-1] == n1 || nums[i-1] == n2) {
					vec.push_back(p->left);
				}
			}
			if(nums[i++] != 0) {
				p->right = new TreeNode(nums[i-1]);
				que.push(p->right);
				if(nums[i-1] == n1 || nums[i-1] == n2) {
					vec.push_back(p->right);
				}
			}
		}
		vec.push_back(root);
		return vec;
	}
};

int main() {
	vector<int> nums = {3,5,1,6,2,0,8,0,0,7,4};
	int p = 4, q = 2;

	Solution solution;
	vector<TreeNode*> root = solution.buildTree(nums, p, q);
	cout << root[2]->val << " " << root[0]->val << " " << root[1]->val << endl;
	TreeNode *res = solution.lowestCommonAncestor(root[2], root[0], root[1]);
	if(res)
		cout << "res: " << res->val << endl;
	else 
		cout << "nullptr" << endl;
}