/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0, size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (i > max) { return false; }
            max = max < i + nums.at(i) ? i + nums.at(i) : max;
        }
        return true;
    }
};
// @lc code=end
