#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isValidBST(TreeNode* root) {
        return minMax(root, INT32_MIN, INT16_MAX);
    }
    bool minMax(TreeNode* root, int MIN, int MAX) {
        if(root == nullptr) return true;
        if(root->val < MIN || root->val > MAX)
            return false;
        return minMax(root->left, MIN, root->val) && minMax(root->right, root->val, MAX);
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
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
            cout << root->val << " ";
            showTree(root->left);
            showTree(root->right);
        }
        else {
            cout << 0 << " ";
        }
    }
};

int main() {
    vector<int> nums = {5,1,4,0,0,3,6};
    nums = {2,1,3};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    // solution.showTree(root);
    // cout << endl;
    bool res = solution.isValidBST(root);
    cout << "res: " << res << endl;
}