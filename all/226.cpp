#include <vector>
#include <iostream>
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* buildTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        queue<TreeNode*> que;
        TreeNode *root = new TreeNode(nums[0]);
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode* p = que.front();
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
    vector<int> nums = {4,2,7,1,3,6,9};

    Solution solution;
    
}