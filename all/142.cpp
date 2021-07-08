#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL) {
            if(fast == NULL) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode *res = head;
                while(res != slow) {
                    slow = slow->next;
                    res = res->next;
                }
                return res;
            }
        }
        return NULL;
    }
    ListNode *buildList(vector<int>& nums, int pos) {
        ListNode *root = new ListNode(0), *p = root, *q = NULL;
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
    void showList(ListNode *root) {
        while(root != NULL) {
            cout << root->val << " ";
            int n;
            cin >> n;
            root = root->next;
        }
    }
};

int main() {
    vector<int> nums = {3,2,0,-4};
    int pos = 1;

    Solution solution;
    ListNode *root = solution.buildList(nums, pos);
    // solution.showList(root);
    ListNode *res = solution.detectCycle(root);
    cout << "res: " << res->val << endl;
}