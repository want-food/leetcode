/*************************************************************************
	> File Name: 124.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 09:23:59 2021
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
	int maxPathSum(TreeNode* root) {
		if(root == nullptr) return  0;

		int ans = root->val;
		maxPathSum(root, ans);
		return ans;
    }
    int maxPathSum(TreeNode* root, int& ans) {
		if(root->left == nullptr && root->right == nullptr) {
			if(ans < root->val) ans = root->val;
			return root->val;
		}

		int l = 0, r = 0;
		if(root->left != nullptr) l = maxPathSum(root->left, ans);
		if(root->right != nullptr) r = maxPathSum(root->right, ans);
		cout << l << " " << root->val << " " << r << endl;
		int Max = root->val + max(0, l) + max(0, r);
		if(Max > ans) ans = Max;
		return root->val + max(l, max(r, 0));
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode *> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode *p = que.front();
            que.pop();

            if(nums[i++] != 0) {
                p->left = new TreeNode(nums[i - 1]);
                que.push(p->left);
            }
            if(nums[i++] != 0) {
                p->right = new TreeNode(nums[i - 1]);
                que.push(p->right);
            }
        }
        return root;
    }
    void showTree(TreeNode *root) {
        if(root != nullptr) {
            showTree(root->left);
            cout << root->val << " ";
            showTree(root->right);
        }
        else {
            cout << "0 ";
        }
    }
};

int main() {
	vector<int> nums = {9,6,-3,0,0,-6,2,0,0,2,0,-6,-6,-6,0,0,0};
	nums = {-2,1,0};

	Solution solution;
	TreeNode *root = solution.buildTree(nums);
	solution.showTree(root);
	cout << endl;
	int res = solution.maxPathSum(root);
	cout << "res: " << res << endl;
}