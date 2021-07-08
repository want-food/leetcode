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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        if(root1 == nullptr) {
            return root2;
        }
        if(root2 == nullptr) {
            return root1;
        }
        TreeNode *l = mergeTrees(root1->left, root2->left);
        TreeNode *r = mergeTrees(root1->right, root2->right);
        root1->val += root2->val;
        root1->left = l;
        root1->right = r;
        return root1;
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

    void showTree(TreeNode *root) {
        if(root) {
            cout << root->val << " ";
            showTree(root->left);
            showTree(root->right);
        }
    }
};

int main() {
    vector<int> num1 = {1,3,2,5,0};
    vector<int> num2 = {2,1,3,0,4,0,7};

    Solution solution;
    TreeNode *root1 = solution.buildTree(num1);
    solution.showTree(root1);
    cout << endl;
    TreeNode *root2 = solution.buildTree(num2);
    solution.showTree(root2);
    cout << endl;
    TreeNode *root = solution.mergeTrees(root1, root2);
    solution.showTree(root);
    cout << endl;
}