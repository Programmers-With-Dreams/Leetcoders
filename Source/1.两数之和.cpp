/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end

