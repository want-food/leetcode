#include <iostream>
#include <vector>
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
    void flatten(TreeNode* root) {
        while(root != nullptr) {
            if(root->left != nullptr) {
                flatten(root->left);
                TreeNode *down = root->left, *next = down->right;
                while(next != nullptr) {
                    next = next->right;
                    down = down->right;
                }
                down->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = down;
            }
            root = root->right;
        }
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
    vector<int> nums = {1,2,5,0,4,0,6};

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    solution.showTree(root);
    cout << endl;

    solution.flatten(root);
    cout << "res: " << endl;
    solution.showTree(root);
    cout << endl;
}