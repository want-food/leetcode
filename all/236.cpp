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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        bool pf = false, qf = false;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l == p || r == p || root == p) lp = true;
        if(l == q || r == q || root == q) lq = true;
        if(lp == true && lq == true) return root;
        if(lp == true) 
    }
    TreeNode *buildTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode *root = new TreeNode(nums[0]);
        queue<TreeNode *> que;
        que.push(root);
        for (int i = 1; i < nums.size(); ) {
            TreeNode *p = que.front();
            que.pop();

            if(nums[i++] != -1) {
                p->left = new TreeNode(nums[i-1]);
                que.push(p->left);
            }
            if(nums[i++] != -1) {
                p->right = new TreeNode(nums[i-1]);
                que.push(p->right);
            }
        }
        return root;
    }
    TreeNode *getroot(TreeNode* root, int i) {
        queue<TreeNode*> que;
        que.push(root);
        while(root != NULL) {
            root = que.front();
            que.pop();
            if(root->val != i) return root;
            if(root->left != NULL) que.push(root->left);
            if(root->right != NULL) que.push(root->right);
        }
        return NULL;
    }
};

int main() {
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    int i = 5, j = 4;

    Solution solution;
    TreeNode *root = solution.buildTree(nums);
    TreeNode *p = solution.getroot(root, i);
    TreeNode *q = solution.getroot(root, j);
    TreeNode *res = solution.lowestCommonAncestor(root, p, q);
    cout << "res: " << res->val << endl;
}