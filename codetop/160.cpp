/*************************************************************************
	> File Name: 160.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 13:00:14 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// // 1. 哈希表
        // unordered_set<ListNode*> map;
		// while(headA != nullptr) {
		// 	map.insert(headA);
		// 	headA = headA->next;
		// }
		// while(headB != nullptr) {
		// 	if(map.find(headB) != map.end()) {
		// 		return headB;
		// 	}
		// 	headB = headB->next;
		// }
		// return nullptr;

		// 2. 双指针法，因为两个链表的长度不一样长
		if(headA == nullptr || headB == nullptr) return nullptr;
		ListNode *p1 = headA, *p2 = headB;
		while(p1 != p2) {
			p1 = p1 == nullptr ? headB : p1->next;
			p2 = p2 == nullptr ? headA : p2->next;
		}
		return p1;
    }
	vector<ListNode*> buildList(vector<int>& nums1, int skip1, vector<int>& nums2, int skip2) {
		ListNode *root1 = new ListNode(0), *root2 = new ListNode(0), *p1, *p2;
		p1 = root1;
		for (int i = 0; i < skip1; i++) {
			p1->next = new ListNode(nums1[i]);
			p1 = p1->next;
		}
		p2 = root2;
		for (int i = 0; i < skip2; i++) {
			p2->next = new ListNode(nums2[i]);
			p2 = p2->next;
		}
		for (int i = skip2; i < nums2.size(); i++) {
			p2->next = new ListNode(nums2[i]);
			if(i == skip2) {
				p1->next = p2->next;
			}
			p2 = p2->next;
		}
		return {root1->next, root2->next};
	}
	void showList(ListNode* root) {
		while(root != nullptr) {
			cout << root->val << " ";
			root = root->next;
		}
		cout << endl;
	}
};

int main() {
	int intersectVal = 8, skipA = 2, skipB = 3;
	vector<int> listA = {4,1,8,4,5}, listB = {5,0,1,8,4,5};

	Solution solution;
	vector<ListNode *> r = solution.buildList(listA, skipA, listB, skipB);
	solution.showList(r[0]);
	solution.showList(r[1]);
	ListNode *ans = solution.getIntersectionNode(r[0], r[1]);
	cout << "res: " ;
	if(ans == nullptr) cout << "nullptr " << endl;
	else cout << ans->val << endl;
}