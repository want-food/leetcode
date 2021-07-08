#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp = {};
        subsets(nums, 0, tmp, res);
        return res;
    }
    void subsets(vector<int> &nums, int index, vector<int>& tmp, vector<vector<int>> &res)
    {
        if(index == nums.size()) {
            res.push_back(tmp);
            return;
        }
        // for (int i = index; i < nums.size(); i++) {
        //     subsets(nums, i + 1, tmp, res);
        //     tmp.push_back(nums[i]);
        //     subsets(nums, i + 1, tmp, res);
        //     tmp.pop_back();
        // }
        subsets(nums, index + 1, tmp, res);
        tmp.push_back(nums[index]);
        subsets(nums, index + 1, tmp, res);
        tmp.pop_back();
    }
};

int main() {
    vector<int> nums = {};
    
    Solution solution;
    vector<vector<int>> res = solution.subsets(nums);
    cout << "res: " << endl;
    for (vector<int>& vec: res) {
        for (int j: vec) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}