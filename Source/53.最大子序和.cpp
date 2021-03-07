/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int max(int a, int b, int c){
        if (a < b) { a = b; }
        if (a < c) { a = c; }
        return a;
    }

    int maxSubRec(vector<int>& nums, int left, int right) {
        if (left + 1 == right) { return nums.at(left);}
        int mid = (left + right) >> 1, leftMax = 0, rightMax = 0;
        int leftMid = 0, rightMid = 0, midMax = 0, leftMidMax = 0, rightMidMax = 0;
        leftMax = maxSubRec(nums, left, mid);
        rightMax = maxSubRec(nums, mid, right);
        if (leftMax < 0 && rightMax < 0) { return leftMax < rightMax ? rightMax : leftMax; }
        for (int i = mid - 1; i >= left; --i) {
            leftMid += nums.at(i);
            if (leftMidMax < leftMid) { leftMidMax = leftMid; }
        }
        for (int i = mid; i < right; ++i){
            rightMid += nums.at(i);
            if (rightMidMax < rightMid) { rightMidMax = rightMid; }
        }
        return max(leftMax, leftMidMax + rightMidMax, rightMax);
    }

    int maxSubArray(vector<int>& nums) {
        // 迭代法
        // int size = nums.size(), sum = nums.at(0);
        // if (size == 1) { return nums.at(0); }
        // auto iter = nums.begin();
        // while (iter != nums.end() && *iter < 0) { sum = sum < *iter ? *iter : sum; ++iter; }
        // while (iter != nums.end()) {
        //     int subSum = 0;
        //     while (iter != nums.end() && *iter + subSum >= 0) {
        //         subSum += *iter++;
        //         if (sum < subSum) { sum = subSum; }
        //     }
        //     if (iter != nums.end()) { ++iter; }
        // }
        // return sum;

        // 递归法
        // return maxSubRec(nums, 0, nums.size());

        // 动态规划, f(x) = max(f(x - 1) + nums[x], nums[x])
        int sum = 0, maxSum = nums.at(0);
        for (auto &item : nums) {
            sum = sum + item < item ? item : sum + item;
            maxSum = maxSum < sum ? sum : maxSum;
        }
        return maxSum;
    }
};
// @lc code=end

