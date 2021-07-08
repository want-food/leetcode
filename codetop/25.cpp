/*************************************************************************
	> File Name: 25.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 01:05:15 2021
 ************************************************************************/

#include <iostream>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
		
    }
	ListNode *buildList(vector<int>& nums) {
		ListNode *root = new ListNode(0), *p = root;
		for (int i: nums) {
			p->next = new ListNode(i);
			p = p->next;
		}
		return root->next;
	}
};

int main() {
	vector<int> nums = {1,2,3,4,5};
	int k = 2;

	Solution solution;
	ListNode *root = solution.buildList(nums);
	ListNode *res = solution.reverseKGroup(root, k);
	cout << "res: " << endl;
	while(res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}