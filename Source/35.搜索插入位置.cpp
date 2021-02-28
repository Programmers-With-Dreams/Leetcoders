/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums.at(0)){ return 0; }
        int begin = 0, end = nums.size(), mid = (begin + end) >> 1;
        while (begin + 1 != end){
            if (nums.at(mid) <= target){ begin = mid; }
            else { end = mid; }
            mid = (begin + end) >> 1;
        }
        if (target == nums.at(begin)){ return begin;}
        return end;
    }
};
// @lc code=end

