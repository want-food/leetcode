/*************************************************************************
	> File Name: 2.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 00:02:19 2021
 ************************************************************************/

#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
		head1->next = l1, head2->next = l2;
		l1 = head1, l2 = head2;
		int n = 0, carry = 0;
		while(l1->next && l2->next) {
			n = l1->next->val + l2->next->val + carry;
			if(n >= 10) {
				n -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			l1->next->val = n;
			l1 = l1->next;
			l2 = l2->next;
		}
		if(l2->next)
			l1->next = l2->next;
		while(l1->next) {
			l1->next->val += carry;
			if(l1->next->val >= 10) {
				l1->next->val -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			l1 = l1->next;
		}
		if(carry == 1) l1->next = new ListNode(1);
		return head1->next;
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
	vector<int> num1 = {};
	vector<int> num2 = {};

	Solution solution;
	ListNode *root1 = solution.buildList(num1);
	ListNode *root2 = solution.buildList(num2);
	ListNode *res = solution.addTwoNumbers(root1, root2);
	cout << "res: " << endl;
	while(res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}