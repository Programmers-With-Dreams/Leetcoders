/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count = 0, size = position.size();
        for (auto &item : position) { count += item & 1; }
        return count < size - count ? count : size - count;
    }
};
// @lc code=end

