#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;

        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric (TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr)
            return true;
        if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr) || (left->val != right->val))
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
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
    vector<int> nums = {1,2,2,3,4,4,3};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    solution.showTree(root);
    cout << endl;
    bool res = solution.isSymmetric(root);
    cout << "res: " << res << endl;
}