/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto begin = nums.begin(), end = nums.begin();
        int subSum = 0, minCount = 10001, subCount = 0;
        while (end != nums.end()) {
            subSum += *end++; ++subCount;
            int flag = subSum - target;
            if (0 <= flag) {
                while (*begin <= flag) {
                    if (begin == end) { break; }
                    subSum -= *begin++; --subCount;
                    flag = subSum - target;
                }
                if (subCount < minCount) { minCount = subCount; }
            }
        }
        if (minCount == 10001) { minCount = 0; }
        return minCount;
    }
};
// @lc code=end

