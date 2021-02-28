/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t size = nums.size();
        unsigned int begin = 0, end = size, mid = (begin + end) >> 1;
        while ((begin + 1) != end){
            if (nums.at(mid) <= target){ begin = mid; }
            else { end = mid; }
            mid = (begin + end) >> 1;
        }
        if (target != nums.at(begin)){ return -1; }
        return begin;
    }
};
// @lc code=end

