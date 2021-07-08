/*************************************************************************
	> File Name: 2.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 00:19:58 2021
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
		ListNode *ans = new ListNode(0), *p = ans;
		int carry = 0;
		while(l1 && l2) {
			l1->val += l2->val + carry;
			if(l1->val >= 10) {
				l1->val -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			p->next = l1;
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1) {
			l1->val += carry;
			if(l1->val >= 10) {
				l1->val -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
		while(l2) {
			l2->val += carry;
			if(l2->val >= 10) {
				l2->val -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
		if(carry == 1) p->next = new ListNode(1);
		return ans->next;
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
	vector<int> nums1 = {2,4,3};
	vector<int> nums2 = {5,6,6};

	Solution solution;
	ListNode *root1 = solution.buildList(nums1);
	ListNode *root2 = solution.buildList(nums2);

	ListNode *res = solution.addTwoNumbers(root1, root2);
	cout << "res: " << endl;
	while(res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}