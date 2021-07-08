/*************************************************************************
	> File Name: 21.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 13:45:37 2021
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *ans = new ListNode(0), *p = ans;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if(l1) {
			p->next = l1;
		}
		if(l2) {
			p->next = l2;
		}
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
	vector<int> l1 = {1,2,4}, l2 = {1,3,4};

	Solution solution;
	ListNode *root1 = solution.buildList(l1);
	ListNode *root2 = solution.buildList(l2);
	ListNode *ans = solution.mergeTwoLists(root1, root2);
	cout << "res: " << endl;
	while(ans) {
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
}