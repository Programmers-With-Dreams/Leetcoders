/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curLocal = 0, size = nums.size(), numOfZero = 0;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter){
            if(*iter == 0){ ++numOfZero; continue; }
            nums.at(curLocal++) = *iter;
        }
        while (curLocal < size){ nums.at(curLocal++) = 0; }
    }
};
// @lc code=end

