/*************************************************************************
	> File Name: 143.cpp
	> Author: dingchen
	> Mail: dingchen@163.com 
	> Created Time: Thu Jul  8 10:16:45 2021
 ************************************************************************/

#include<iostream>
#include <vector>
#include <unordered_map>

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
    void reorderList(ListNode* head) {
		// // 1. 线性链表
		// vector<ListNode*> vec;
		// while(head != nullptr) {
		// 	vec.push_back(head);
		// 	head = head->next;
		// }
		// ListNode *ans = new ListNode(0), *p = ans;
		// int size = vec.size(), left = 0, right = size-1;
		// while(left <= right) {
		// 	if(left == right) {
		// 		p->next = vec[left++];
		// 		p = p->next;
		// 		break;
		// 	}
		// 	p->next = vec[left++];
		// 	p = p->next;
		// 	p->next = vec[right--];
		// 	p = p->next;
		// }
		// p->next = nullptr;

		// 2. 寻找链表中点，链表逆序，合并链表
		if(head ==  nullptr) return;
		// 寻找链表中点
		ListNode *Head = new ListNode(0), *fast = Head, *slow = Head;
		Head->next = head;
		while(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
			if(fast != nullptr) {
				fast = fast->next;
			}
		}
		
		// 2. 链表逆序
		
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
	vector<int> nums = {1,2,3};

	Solution solution;
	ListNode *root = solution.buildList(nums);
	solution.reorderList(root);
	cout << "res: " << endl;
	while(root) {
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}