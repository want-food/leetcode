#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int num: nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
            if(nums[i] <= n) res.push_back(i+1);
        }
        cout << endl;
        return res;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution solution;
    vector<int> res = solution.findDisappearedNumbers(nums);
    cout << "res: " << endl;
    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
}