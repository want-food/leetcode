#include <vector>
#include <iostream>
#include <stack>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<TreeNode *> que;
        que.push(root);
        vector<vector<int>> res;
        int l1 = 1;
        while (!que.empty()) {
            int l2 = 0;
            vector<int> r;
            for (int i = 0; i < l1; i++) {
                root = que.front();
                que.pop();
                r.push_back(root->val);
                if(root->left != nullptr) {
                    l2++;
                    que.push(root->left);
                }
                if(root->right != nullptr) {
                    l2++;
                    que.push(root->right);
                }
            }
            l1 = l2;
            res.push_back(r);
        }
        return res;
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
    vector<int> nums = {3, 9, 20, 0, 0, 15, 7};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    vector<vector<int>> res = solution.levelOrder(root);
    cout << "res: " << endl;
    for (vector<int>& vec: res) {
        for (int i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}