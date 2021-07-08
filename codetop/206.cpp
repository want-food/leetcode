/*************************************************************************
	> File Name: 206.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Fri Jul  2 23:19:27 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

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
		if(head == nullptr) return nullptr;
		ListNode *front = head, *back = head->next, *p;
		while(back != nullptr) {
			p = back->next;
			back->next = front;
			front = back;
			back = p;
		}
		head->next = nullptr;
		return front;
    }
	ListNode *buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		// if(nums.size() == 0) return root->next;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			p->next = new ListNode(nums[i]);
			p = p->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> nums = {};

	Solution solution;
	ListNode *root = solution.buildList(nums);
	ListNode *res = solution.reverseList(root);
	cout << "res: " << endl;
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}