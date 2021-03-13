/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permuteRec(nums, 0, nums.size());
        return result;
    }

private:
    vector<vector<int>> result;

    void permuteRec(vector<int> &nums, int begin, int end){
        if (begin == end){ result.push_back(nums); return; }
        for (int i = begin; i < end; ++i){
            int temp = nums.at(begin); nums.at(begin) = nums.at(i); nums.at(i) = temp;
            permuteRec(nums, begin + 1, end);
            temp = nums.at(begin); nums.at(begin) = nums.at(i); nums.at(i) = temp;
        }
    }
};
// @lc code=end

