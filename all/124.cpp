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
    int maxPathSum(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if(root->left == nullptr) {
            int r = maxPathSum(root->right);
            return max(root->val, max(r, r + root->val));
        }
        if(root->right == nullptr) {
            int r = maxPathSum(root->left);
            return max(root->val, max(r, r + root->val));
        }

        int r1 = maxPathSum(root->left);
        int r2 = maxPathSum(root->right);
        cout << root->val << " " << r1 << " " << r2 << endl;
        // return max(max(r1 + r2 + root->val, root->val), max(r1, r2));
        return max(max(root->val, max(r1, r2)), max(max(r1 + root->val, r2 + root->val), r1 + r2 + root->val));
    }
    TreeNode *buildTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode *> que;
        que.push(root);
        for (int i = 1; i < nums.size();)
        {
            TreeNode *p = que.front();
            que.pop();

            if (nums[i++] != 0)
            {
                p->left = new TreeNode(nums[i - 1]);
                que.push(p->left);
            }
            if (nums[i++] != 0)
            {
                p->right = new TreeNode(nums[i - 1]);
                que.push(p->right);
            }
        }
        return root;
    }
    void showTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            showTree(root->left);
            cout << root->val << " ";
            showTree(root->right);
        }
        else
            cout << "0 ";
    }
};

int main() {
    vector<int> nums = {-10, 9, 20, 0, 0, 15, 7};
    nums = {1, -2, -3, 1, 3, -2, 0, -1};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    int res = solution.maxPathSum(root);
    cout << "res: " << res << endl;
}