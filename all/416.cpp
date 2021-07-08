#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int sum = 0;
         for (int i: nums) {
             sum += i;
         }
         if(sum % 2 == 1) return false;

         sum /= 2;
         int n = nums.size();
         vector<bool> vec(sum+1, false);
         for (int i: nums) {
             if(nums[i] == sum) return true;
             if(nums[i] > sum) return false;
             for (int j = sum; j >= 0; j--) {
                 if(vec[j] == true && j + i <= sum) {
                     vec[j + i] = true;
                 }
             }
             vec[i] = true;
             for (int i: vec) {
                cout << i << " ";
            }
            cout << endl;
         }
         for (int i: vec) {
             cout << i << " ";
         }
         cout << endl;
         return vec[sum];
    }
};

int main() {
    vector<int> nums = {2,2,3,5};

    Solution solution;
    bool res = solution.canPartition(nums);
    cout << "res: " << res << endl;
}