/*************************************************************************
	> File Name: 142.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Mon Jul  5 00:08:14 2021
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
    ListNode *detectCycle(ListNode *head) {
		if(head == nullptr || head->next == nullptr) return nullptr;

		ListNode *fast = head->next->next, *slow = head->next;
		while(fast != slow) {
			if(fast == nullptr || fast->next == nullptr) return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *ans = head;
		while(slow != ans) {
			ans = ans->next;
			slow = slow->next;
		}
		return ans;
    }
	ListNode *buildList(vector<int>& nums, int pos) {
		ListNode *root = new ListNode (0), *p = root, *q = nullptr;

		for (int i = 0; i < nums.size(); i++) {
			p->next = new ListNode(nums[i]);
			p = p->next;
			if(i == pos) {
				q = p;
			}
		}
		p->next = q;
		return root->next;
	}
};

int main() {
	vector<int> nums = {3,2,0,-4};
	int pos = 0;

	Solution solution;
	ListNode *root = solution.buildList(nums, pos);
	ListNode *res = solution.detectCycle(root);
	cout << "res: " << res->val << endl;
}