#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        // left左边是非负数，右边是零
        while(right < n) {
            if(nums[right] != 0) {
                nums[left++] = nums[right];
            }
            right++;
        }
        while(left < n) {
            nums[left++] = 0;
        }
        return ;
    }
};

int main() {
    vector<int> nums = {};

    Solution solution;
    solution.moveZeroes(nums);
    cout << "res: " << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}