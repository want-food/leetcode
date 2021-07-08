/*************************************************************************
	> File Name: 141.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 13:52:11 2021
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
    bool hasCycle(ListNode *head) {
		if(head == nullptr) return false;
		ListNode *p1 = head, *p2 = head->next;
		while(p1 && p2) {
			if(p1 == p2) return true;
			p1 = p1->next;
			p2 = p2->next;
			if(p2 != nullptr) p2 = p2->next;
		}
		return false;
    }
	ListNode *buildList(vector<int>& nums, int pos) {
		ListNode *root = new ListNode(0), *p = root, *q = nullptr;
		for (int i = 0; i < nums.size(); i++) {
			p->next = new ListNode(nums[i]);
			p = p->next;
			if(i == pos) q = p;
		}
		p->next = q;
		return root->next;
	}
};

int main() {
	vector<int> nums = {};
	int pos = -1;

	Solution solution;
	ListNode *root = solution.buildList(nums, pos);
	bool res = solution.hasCycle(root);
	cout << "res: " << res << endl;
}