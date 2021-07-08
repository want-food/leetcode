/*************************************************************************
	> File Name: 15.cpp
	> Author: dingchen
	> Mail: 18811502859@163.com 
	> Created Time: Sun Jul  4 10:14:43 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
		int left, mid, right;
		for (left = 0; left < len-2; left++) {
			if(left != 0 && nums[left] == nums[left-1]) continue;
			int target = -nums[left];
			mid = left+1, right = len-1;
			while(mid < right) {
				if(mid > left+1 && nums[mid] == nums[mid-1]) {
					mid++;
					continue;
				}
				if(nums[mid] + nums[right] == target) {
					ans.push_back({nums[left], nums[mid], nums[right]});
					mid++;
				}
				else if(nums[mid] + nums[right] > target) {
					right--;
				}
				else {
					mid++;
				}
			}
		}
		return ans;



        // // 枚举 a
        // for (int first = 0; first < n; ++first) {
        //     // 需要和上一次枚举的数不相同
        //     if (first > 0 && nums[first] == nums[first - 1]) {
        //         continue;
        //     }
        //     // c 对应的指针初始指向数组的最右端
        //     int third = n - 1;
        //     int target = -nums[first];
        //     // 枚举 b
        //     for (int second = first + 1; second < n; ++second) {
        //         // 需要和上一次枚举的数不相同
        //         if (second > first + 1 && nums[second] == nums[second - 1]) {
        //             continue;
        //         }
        //         // 需要保证 b 的指针在 c 的指针的左侧
        //         while (second < third && nums[second] + nums[third] > target) {
        //             --third;
        //         }
        //         // 如果指针重合，随着 b 后续的增加
        //         // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
        //         if (second == third) {
        //             break;
        //         }
        //         if (nums[second] + nums[third] == target) {
        //             ans.push_back({nums[first], nums[second], nums[third]});
        //         }
        //     }
        // }
        // return ans;
    }
};

int main() {
	vector<int> nums = {-1,0,1,2,-1,-4};

	Solution solution;
	vector<vector<int>> res = solution.threeSum(nums);
	cout << "res:" << endl;
	for (vector<int> r: res) {
		for (int i: r) {
			cout << i << " ";
		}
		cout << endl;
	} 
	cout << endl;
}