/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int frontFib = 0, Fib = 1, temp;
        if (!n) { return 0; }
        while (--n){ temp = frontFib; frontFib = Fib; Fib = temp + frontFib; }
        return Fib;
    }
};
// @lc code=end

