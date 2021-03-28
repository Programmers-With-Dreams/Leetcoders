/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 0; i < m - 1; ++i) {
            for (int i = 1; i < n; ++i) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

