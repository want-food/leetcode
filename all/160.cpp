#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *l1 = headA, *l2 = headB;
		while(l1 != l2) {
			l1 = l1 == NULL ? headB : l1->next;
			l2 = l2 == NULL ? headA : l2->next;
		}
		return l1;
	}
	ListNode *buildList(vector<int>& nums) {
		ListNode *head = new ListNode(0), *p = head;
		for (int i = 0; i < nums.size(); i++) {
			p->next = new ListNode (nums[i]);
			p = p->next;
		}
		return head->next;
	}
	void showList(ListNode *root) {
		while(root != NULL) {
			cout << root->val << " ";
			root = root->next;
		}
		cout << endl;
	}
};

int main() {
	vector<int> num1 = {4,1,8,4,5};
	vector<int> num2 = {5,0,1,8,4,5};

	Solution solution;
	
	ListNode *headA = solution.buildList(num1);
	ListNode *headB = solution.buildList(num2);
	
	solution.showList(headA);
	solution.showList(headB);

	ListNode *res = solution.getIntersectionNode(headA, headB);
	cout << "res: " << res->val << endl;
}
