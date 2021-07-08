/*************************************************************************
	> File Name: 21.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 09:32:55 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){} 
	ListNode(int x) : val(x), next(nullptr){} 
	ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(0), *p = res;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val <= l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if(l1 != nullptr) {
			p->next = l1;
		}
		if(l2 != nullptr) {
			p->next = l2;
		}
		return res->next;
	}
	ListNode* buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		for (int n: nums) {
			p->next = new ListNode(n);
			p = p->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> nums1 = {}, nums2 = {};

	Solution solution;
	ListNode *r1 = solution.buildList(nums1);
	ListNode *r2 = solution.buildList(nums2);

	ListNode *res = solution.mergeTwoLists(r1, r2);
	cout << "===res===" << endl;
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}