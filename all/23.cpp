/*************************************************************************
	> File Name: 23.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Thu May 20 10:01:25 2021
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){} 
	ListNode(int x) : val(x), next(nullptr){} 
	ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		bool end = false;
		ListNode *res = new ListNode(0), *p, *r = res;
		while(1) {
			int MIN = INT32_MAX;
			end = true;
			cout << "=========" << endl;
			int ii;
			for (int i = 0; i < len; i++) {
				if(lists[i] != nullptr) {
					// cout << lists[i]->val << " ";
					end = false;
					if(MIN > lists[i]->val) {
						MIN = lists[i]->val;
						p = lists[i];
						ii = i;
					}
				}
				// else
				// 	cout << -1 << " ";
			}
			if (end == true)
				break;
			cout << endl;
			r->next = lists[ii];
			r = r->next;
			lists[ii] = lists[ii]->next;
		}
		return res->next;
	}
	vector<ListNode*> buildList(vector<vector<int>>& nums) {
		vector<ListNode*> res;
		for (vector<int>& vec: nums) {
			ListNode *root = new ListNode(0), *p = root;
			for (int& n: vec) {
				p->next = new ListNode(n);
				p = p->next;
			}
			res.push_back(root->next);
		}
		return res;
	}
};

int main() {
	int n = 3;
	// vector<vector<int>> nums = { {1, 4, 5},
	// 							 {1, 3, 4},
	// 							 {2, 6} };
	vector<vector<int>> nums = {{1}};

	Solution solution;
	vector<ListNode *> vecList = solution.buildList(nums);

	ListNode *res = solution.mergeKLists(vecList);
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}