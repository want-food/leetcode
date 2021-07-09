/*************************************************************************
	> File Name: 19.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Tue Jul  6 08:27:41 2021
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *Head = new ListNode(0), *slow = Head, *fast = head; 
		Head->next = head;

		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		while(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		cout << slow->val << endl;
		slow->next = slow->next->next;
		return Head->next;
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
	vector<int> nums = {1,2};
	int n = 1;

	Solution solution;
	ListNode *root = solution.buildList(nums);
	ListNode *res = solution.removeNthFromEnd(root, n);
	cout << "res: " << endl;
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}