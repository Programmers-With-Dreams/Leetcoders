/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), max = 0, profit = 0;
        for (int i = size - 1; i >= 0; --i) {
            max = max < prices.at(i) ? prices.at(i) : max;
            profit = profit < max - prices.at(i) ? max - prices.at(i) : profit;
        }
        return profit;
    }
};
// @lc code=end

