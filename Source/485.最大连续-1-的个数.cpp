/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0, max = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++){
            if (*iter){ ++sum; if (max < sum){ max = sum; }}
            else{ sum = 0; }
        }
        return max;
    }
};
// @lc code=end

