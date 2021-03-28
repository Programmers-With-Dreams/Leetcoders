/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // f(i) = f(i - 1) + f(i - 2), f(1) = 1,f(2) = 2
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }
        int low = 1, curr = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = curr;
            curr += low;
            low = temp;
        }
        return curr;
    }
};
// @lc code=end

