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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;

        TreeNode *r = convertBST(root->right);
        while(r != nullptr && r->left != nullptr) {
            r = r->left;
        }
        if(r != nullptr) root->val += r->val;
        TreeNode *l = root->left;
        while(l != nullptr && l->right != nullptr) {
            l = l->right;
        }
        if(l != nullptr) l->val += root->val;
        l = convertBST(root->left);
        return root;
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode*> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode *p = que.front();
            que.pop();
            if(nums[i++] != -1) {
                p->left = new TreeNode(nums[i-1]);
                que.push(p->left);
            }
            if(nums[i++] != -1) {
                p->right = new TreeNode(nums[i-1]);
                que.push(p->right);
            }
        }
        return root;
    }
    void showTree(TreeNode *root) {
        if(root) {
            cout << root->val << " ";
            showTree(root->left);
            showTree(root->right);
        }
    }
};

int main() {
    vector<int> nums = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    solution.showTree(root);
    cout << endl;
    TreeNode *res = solution.convertBST(root);
    solution.showTree(res);
    cout << endl;
}