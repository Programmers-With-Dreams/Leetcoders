/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        // f(n) = min{f(n - num[i]*num[i])} + 1
        vector<int> squares;
        for (int i = sqrt(n); i > 0; --i) { squares.push_back(i); }
        vector<int> dp(n + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            int minCost = 10001;
            for (auto &square : squares) {
                int cal = i - square * square;
                if (cal < 0) { continue; }
                else { if (dp[cal] < minCost) { minCost = dp[cal]; } }
            }
            dp[i] = minCost + 1;
        }
        return dp[n];
    }
};
// @lc code=end
