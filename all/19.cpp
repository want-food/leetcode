/*************************************************************************
	> File Name: 19.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 09:05:55 2021
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 双指针方法，可以只遍历一遍
		ListNode *res = new ListNode(0);
		res->next = head;
		ListNode *fast = res, *slow = res;
		for (int i = 0; i <= n; i++) {
			fast = fast->next;
		}
		while(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;

		return res->next;
	}
	ListNode* buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		for (int& i: nums) {
			p->next = new ListNode(i);
			p = p->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> nums = {1,2,3,4,5};
	int n = 5;

	Solution solution;
	ListNode *root = solution.buildList(nums);
	ListNode *res = solution.removeNthFromEnd(root, n);
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}