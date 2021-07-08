#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        int l = diameterOfSingleTree(root->left, res);
        int r = diameterOfSingleTree(root->right, res);
        cout << l << " " << r << endl;
        r = l + r + 1;
        if(r > res) res = r;
        return res-1;
    }
    int diameterOfSingleTree(TreeNode *root, int& res) {
        if(root == nullptr) return 0;
        int l = diameterOfSingleTree(root->left, res);
        int r = diameterOfSingleTree(root->right, res);
        cout << root->val << " " << l << " " << r << endl;
        int ans = l + r + 1;
        if(ans > res) res = ans;
        return max(r, l) + 1;
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode*> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode *p = que.front();
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
    vector<int> nums = {1,2,3,4,5};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    int res = solution.diameterOfBinaryTree(root);
    cout << "res: " << res << endl;
}