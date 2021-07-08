/*************************************************************************
	> File Name: 199.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jul  5 23:48:47 2021
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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		DFS(root, 0, res);
		return res;
    }
	void DFS(TreeNode* root, int depth, vector<int>& res) {
		if(root == nullptr) return;
		if(depth < res.size()) {
			res[depth] = root->val;
		}
		else {
			res.push_back(root->val);
		}
		DFS(root->left, depth+1, res);
		DFS(root->right, depth+1, res);
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
	vector<int> nums = {1,2,3,0,5,0,0};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	vector<int> res = solution.rightSideView(root);
	cout << "res: " << endl;
	for(int i: res) {
		cout << i << " ";
	}
	cout << endl;
}