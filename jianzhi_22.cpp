/*************************************************************************
	> File Name: jianzhi_22.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 11:07:56 2021
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; i++) {
			fast = fast->next;
		}
		while(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
    }
	ListNode* buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		for (int i = 0; i < nums.size(); i++) {
			p->next = new ListNode(nums[i]);
			p = p->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> nums = {1,2,3,4,5};
	int k = 2;

	Solution solution;
	ListNode *root = solution.buildList(nums);
	ListNode *ans = solution.getKthFromEnd(root, k);
	cout << "res: " << ans->val << endl;
}