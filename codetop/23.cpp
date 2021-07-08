/*************************************************************************
	> File Name: 23.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Tue Jul  6 00:16:48 2021
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) return {};
		int nums = 0, len = lists.size();
		ListNode *ans = new ListNode(0), *q = ans;
		while(1) {
			int Min = INT32_MAX, k = -1, counts = 0;
			for (int i = 0; i < len; i++) {
				if(lists[i] != nullptr) {
					if(lists[i]->val < Min) {
						Min = lists[i]->val;
						k = i;
					}
					counts++;
				}
			}
			if(counts == 0) break;
			q->next = lists[k];
			q = q->next;
			lists[k] = lists[k]->next;
		}
		return ans->next;
    }
	vector<ListNode*> buildLists(vector<vector<int>>& nums) {
		vector<ListNode*> roots;
		for (vector<int>& vec: nums) {
			ListNode* root = new ListNode(0), *p = root;
			for (int i = 0; i < vec.size(); i++) {
				p->next = new ListNode(vec[i]);
				p = p->next;
			}
			roots.push_back(root->next);
		}
		return roots;
	}
	void showLists(vector<ListNode*> lists) {
		for (int i = 0; i < lists.size(); i++) {
			while(lists[i]) {
				cout << lists[i]->val << " ";
				lists[i] = lists[i]->next;
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	vector<vector<int>> nums = {
		{1,4,5},
		{1,3,4},
		{2,6},
	};
	Solution solution;
	vector<ListNode *> roots = solution.buildLists(nums);
	solution.showLists(roots);
	ListNode* res = solution.mergeKLists(roots);
	cout << "res: ";
	while(res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}