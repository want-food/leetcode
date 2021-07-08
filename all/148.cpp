#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }
    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr)
            return nullptr;
        if(head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode *fast = head, *slow = head;
        while(fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast == tail) {
                break;
            }
            fast = fast->next;
        }
        ListNode *l1 = sortList(head, slow);
        ListNode *l2 = sortList(slow, tail);
        return merge(l1, l2);
    }
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0), *p = res;
        while (l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 != nullptr) {
            p->next = l1;
        }
        if(l2 != nullptr) {
            p->next = l2;
        }
        return res->next;
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
    vector<int> nums = {4,2,1,3};

    Solution solution;
    ListNode *root = solution.buildList(nums);
    ListNode *res = solution.sortList(root);
    cout << "res: " << endl;
    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}