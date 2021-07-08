/*************************************************************************
	> File Name: 2.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun May 16 21:29:52 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0), *l = res;

		int carry = 0;
		while(l1 != NULL && l2 != NULL) {
			int n = l1->val + l2->val + carry;
			if(n >= 10) {
				carry = 1;
				n = n - 10;
			}
			else {
				carry = 0;
			}
			l->next = new ListNode(n);
			l = l->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1 != NULL) {
			int n = l1->val + carry;
			if(n >= 10) {
				carry = 1;
				n = n - 10;
			}
			else{
				carry = 0;
			}
			l->next = new ListNode(n);
			l = l->next;
			l1 = l1->next;
		}
		while(l2 != NULL) {
			int n = l2->val + carry;
			if(n >= 10) {
				carry = 1;
				n = n - 10;
			}
			else{
				carry = 0;
			}
			l->next = new ListNode(n);
			l = l->next;
			l2 = l2->next;
		}
		if(carry == 1) {
			l->next = new ListNode(1);
		}
		return res->next;
	}
	ListNode *buildList(vector<int>& nums) {
		if(nums.size() == 0) return NULL;

		ListNode *root = new ListNode(0), *l = root;
		for (int i: nums){
			l->next = new ListNode(i);
			l = l->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> num1 = {2,4,3}, num2 = {5,6,4};

	Solution solution;
	ListNode *l1 = solution.buildList(num1), *l2 = solution.buildList(num2);

	ListNode *r = solution.addTwoNumbers(l1, l2);
	while(r != NULL) {
		cout << r->val << " ";
		r = r->next;
	}
}