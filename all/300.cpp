#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int res = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			int tmp = nums[i], r = 1;
			for (int j = i+1; j < n; j++) {
				if(nums[j] > tmp) {
					tmp = nums[j];
					r++;
					cout << tmp << " ";
				}
			}
			cout << endl;
			res = max(r, res);
		}
		return res;
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
	nums = {0,1,0,3,2,3};

    Solution solution;
    int res = solution.lengthOfLIS(nums);
    cout << "res: " << res << endl;
}
