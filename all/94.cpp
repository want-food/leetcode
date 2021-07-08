#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root) {
        // // 1. 递归
        // vector<int> res;
        // inorder(root, res);
        // return res;

        // 2. 迭代
        vector<int> res;
        stack<TreeNode *> stk;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
    void inorder(TreeNode *root, vector<int>& res) {
        if(root != nullptr) {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        TreeNode *root;
        queue<TreeNode *> que;
        root = new TreeNode(nums[0]);
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode *p = que.front();
            que.pop();
            if(nums[i++] != -1) {
                p->left = new TreeNode(nums[i - 1]);
                que.push(p->left);
            }
            if(nums[i++] != -1) {
                p->right = new TreeNode(nums[i - 1]);
                que.push(p->right);
            }
        }
        return root;
    }
    void showTree(TreeNode *root) {
        if(root != nullptr) {
            cout << root->val << " ";
            showTree(root->left);
            showTree(root->right);
        }
        else
            cout << 0 << " ";
    }
};

int main() {
    vector<int> nums = {1, -1, 2, 3};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    // solution.showTree(root);
    // cout << endl;
    vector<int> res = solution.inorderTraversal(root);
    cout << "===res===" << endl;
    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
}