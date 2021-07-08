/*************************************************************************
	> File Name: 337.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 28 23:49:46 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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
    int rob(TreeNode* root) {
		vector<int> vec = robRoot(root);
		return max(vec[0], vec[1]);
    }
	vector<int> robRoot(TreeNode* root) {
		if(root == nullptr) return {0, 0};

		// vec[0]
		vector<int> l = robRoot(root->left);
		vector<int> r = robRoot(root->right);
		return {root->val + l[1] + r[1], max(l[0], l[1])+max(r[0], r[1])};
	}
	TreeNode *buildTree(vector<int>& nums) {
		if(nums.size() == 0) return nullptr;

		TreeNode *root = new TreeNode(nums[0]);
		queue<TreeNode*> que;
		que.push(root);
		for (int i = 1; i < nums.size(); ) {
			TreeNode* p = que.front();
			que.pop();

			if(nums[i++] != 0) {
				p->left = new TreeNode(nums[i-1]);
				que.push(p->left);
			}
			if(nums[i++] != 0) {
				p->right = new TreeNode (nums[i-1]);
				que.push(p->right);
			}
		}
		return root;
	}
};

int main() {
	vector<int> nums = {3,2,3,0,3,0,1};
	nums = {3,4,5,1,3,0,1};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	int res = solution.rob(root);
	cout << "res: " << res << endl;
}
