/*************************************************************************
	> File Name: 206.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jun 14 00:33:08 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		// 1. 
		// stack<ListNode *> stk;
		// while(head) {
		// 	stk.push(head);
		// 	head = head->next;
		// }
		// ListNode *res = new ListNode(0);
		// head = res;
		// while(!stk.empty()) {
		// 	head->next = stk.top();
		// 	head = head->next;
		// 	stk.pop();
		// }
		// head->next = nullptr;
		// return res->next;
		
		// 2. 
		if(head == nullptr || head->next == nullptr) return head;

		ListNode *newhead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
	ListNode *buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		for (int i: nums) {
			p->next = new ListNode (i);
			p = p->next;
		}
		return root->next;
	}
	void showList(ListNode *root) {
		while(root) {
			cout << root->val << " ";
			root = root->next;
		}
		cout << endl;
	}
};

int main() {
	vector<int> nums = {1,2,3,4,5};

	Solution solution;
	ListNode *root = solution.buildList(nums);
	solution.showList(root);
	ListNode *res = solution.reverseList(root);
	solution.showList(res);
}
