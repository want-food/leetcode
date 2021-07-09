/*************************************************************************
	> File Name: 105.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 10:42:54 2021
 ************************************************************************/

#include<iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
        if(l1 == r1) return new TreeNode(preorder[l1]);
        if(l1 > r1) return nullptr;
        
        int mid = 0;
        while(preorder[l1] != inorder[l2+mid]) {
            mid++;
        }
        cout << "root: " << preorder[l1] << endl;
        TreeNode *root = new TreeNode(preorder[l1]);
        root->left = buildTree(preorder, inorder, l1+1, l1+mid, l2, l2+mid-1);
        root->right = buildTree(preorder, inorder, l1+mid+1, r1, l2+mid+1, r2);
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
	vector<int> preorder = {1,2,4,5,3,6,7};
	vector<int> inorder = {4,2,5,1,6,3,7};
	// preorder = {1,2};
	// inorder = {2,1};

	Solution solution;
	TreeNode* root = solution.buildTree(preorder, inorder);
	cout << "res: " << endl;
	solution.showTree(root);
	cout << endl;
}