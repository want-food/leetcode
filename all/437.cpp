#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>

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
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        queue<TreeNode *> que;
        while(root != nullptr || que.size() != 0) {
            while(root != nullptr) {
                que.push(root);
                root = root->left;
            }
            root = que.front();
            que.pop();
            cout << root->val << endl;
            // pathSum(root, targetSum, 0);
            root = root->right;
        }
        return res;
    }
    void pathSum(TreeNode *root, int& targetSum, int sum) {
        if(root == nullptr) return ;

        if(root->val + sum == targetSum) {
            res++;
            cout << root->val << " " << sum << endl;
        }
        pathSum(root->left, targetSum, sum + root->val);
        pathSum(root->right, targetSum, sum + root->val);
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode*> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode* p = que.front();
            que.pop();
            if(nums[i++] != 1000001) {
                p->left = new TreeNode(nums[i-1]);
                que.push(p->left);
            }
            if(nums[i++] != 1000001) {
                p->right = new TreeNode(nums[i-1]);
                que.push(p->right);
            }
        }
        return root;
    }
};

int main() {
    vector<int> nums = {10,5,-3,3,2,1000001,11,3,-2,1000001,1};
    int sum = 8;

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    int res = solution.pathSum(root, sum);
    cout << "res: " << res << endl;
}