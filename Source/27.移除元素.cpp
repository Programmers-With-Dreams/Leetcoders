/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curLocal = 0;
        bool changed = false;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter){
            if (*iter == val){ changed = true; continue; }
            if (changed){ nums.at(curLocal) = *iter; }
            ++curLocal;
        }
        return curLocal;
    }
};
// @lc code=end

