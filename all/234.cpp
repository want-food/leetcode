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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        // // 1. 暴力解法
        // vector<int> nums;
        // while(head != nullptr) {
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // int left = 0, right = nums.size() - 1;
        // while(left < right) {
        //     if(nums[left] != nums[right]) {
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;

        // 2. 将后半部分反转
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        while(fast != nullptr) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        while(head != nullptr) {
            cout << head->val << " " << slow->val << endl;
            if(head->val != slow->val) return false;
            if(head == slow || head->next == slow) break;
            head = head->next;
            slow = slow->next;
        }
        return true;
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
    vector<int> nums = {1,2,3,2,1};

    Solution solution;
    ListNode *root = solution.buildList(nums);
    bool res = solution.isPalindrome(root);
    cout << "res: " << res << endl;
}
