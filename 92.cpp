/*************************************************************************
	> File Name: 92.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Mon Jul  5 11:30:01 2021
 ************************************************************************/

#include<iostream>
#include <vector>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode *Head = new ListNode(0);
		Head->next = head;

		ListNode *begin = Head, *end = Head;
		for (int i = 0; i < left-1; i++) {
			begin = begin->next;
		}
		cout << "begin: " << begin->val << endl;
		for (int i = 0; i < right; i++) {
			end = end->next;
		}
		cout << "end: " << end->val << endl;
		ListNode *last = end->next;

		ListNode *p = begin->next;
		while(p != end) {
			ListNode *tmp = p->next;
			p->next = last;
			last = p;
			p = tmp;
		}
		begin->next = end;
		end->next = last;
		return Head->next;
    }
	ListNode *buildList(vector<int>& nums) {
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
	int left = 2, right = 3;

	Solution solution;
	ListNode *root = solution.buildList(nums);
	root = solution.reverseBetween(root, left, right);
	cout << "res: " << endl;
	while(root) {
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}