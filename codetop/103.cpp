/*************************************************************************
	> File Name: 103.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 22:57:06 2021
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if(root == nullptr) return {};

		vector<vector<int>> res;
		int count = 1, row = 0;
		queue<TreeNode *> que;
		que.push(root);
		vector<int> vec;
		while(que.size() != 0) {
			TreeNode *p = que.front();
			que.pop();
			vec.push_back(p->val);
			count--;

			if(p->left) que.push(p->left);
			if(p->right) que.push(p->right);
			
			if(count == 0) {
				count = que.size();
				if(row % 2 == 1)
					reverse(vec.begin(), vec.end());
				res.push_back(vec);
				vec = {};
				row++;
			}
		}
		return res;
    }
	TreeNode *buildTree(vector<int>& nums) {
		if(nums.size() == 0) return nullptr;

		queue<TreeNode*> que;
		TreeNode *root = new TreeNode(nums[0]);
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
	vector<int> nums = {1,2,3,4,0,0,5};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	vector<vector<int>> res = solution.zigzagLevelOrder(root);
	cout << "res: " << endl;
	for (vector<int>& vec: res) {
		for (int i: vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}