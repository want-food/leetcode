#include <iostream>
#include <vector>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
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
    vector<int> nums = {3,9,20,0,0,15,7};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    int maxDepth = solution.maxDepth(root);
    cout << "res: " << maxDepth << endl;
}