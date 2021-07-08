#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len == 0)
            return nullptr;

        int i = 0;
        for ( ; i < len; i++) {
            if(preorder[0] == inorder[i]) {
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[0]);
        root->left = buildTree(preorder, 1, i, inorder, 0, i - 1);
        root->right = buildTree(preorder, i + 1, len - 1, inorder, i + 1, len - 1);
        return root;
    }
    TreeNode *buildTree(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1)
            return nullptr;
        if(l1 == r1)
            return new TreeNode(preorder[l1]);
        int i = 0;
        for (; i <= r1 - l1; i++) {
            if(preorder[l1] == inorder[l2 + i]) {
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[l1]);
        root->left = buildTree(preorder, l1 + 1, l1 + i, inorder, l2, l2 + i - 1);
        root->right = buildTree(preorder, l1 + i + 1, r1, inorder, l2 + i + 1, r2);
        return root;
    }
    void showTree (TreeNode *root) {
        if (root != nullptr) {
            showTree(root->left);
            cout << root->val << " ";
            showTree(root->right);
        }
        else
            cout << "0 ";
    }
};

int main() {
    // 前序遍历 preorder = [3,9,20,15,7]
    // 中序遍历 inorder = [ 9, 3, 15, 20, 7 ]
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);
    solution.showTree(root);
    cout << endl;
}