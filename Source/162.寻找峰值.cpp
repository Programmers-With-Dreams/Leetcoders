/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        // if (end == 1 || nums.at(1) < nums.at(0)){ return 0; }
        // if (nums.at(end - 2) < nums.at(end - 1)){ return end - 1; }
        // ++begin; --end;
        // for (int i = 1; i < size; i++){
        //     if (nums.at(i - 1) < nums.at(i)){
        //         if (nums.at(i + 1) < nums.at(i)){ return i; }
        //     }
        // }
        // return -1;
        while (begin < end){
            int mid = (begin + end) >> 1;
            if (nums.at(mid) < nums.at(mid + 1)){ begin = mid + 1; }
            else { end = mid; }
        }
        return begin;
    }
};
// @lc code=end