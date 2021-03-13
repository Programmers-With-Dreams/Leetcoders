/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 回溯解法
        // int size = nums.size();
        // for (int i = 0; i <= size; i++) {
        //     vector<int> temp;
        //     subsetRec(nums, temp, 0, i);
        // }
        // return results;

        // 递归解法
        vector<vector<int>> results;
        int size = nums.size();
        for (int mask = 0; mask < (1 << size); ++mask) {
            vector<int> temp;
            for (int i = 0; i < size; ++i) { if (mask & (1 << i)) { temp.push_back(nums.at(i)); } }
            results.push_back(temp);
        }
        return results;
    }
// private:
    // vector<vector<int>> results;

    // void subsetRec(vector<int> &nums,vector<int> &result, int begin, int subSize) {
    //     if(!subSize) { results.push_back(result); return; }
    //     int size = nums.size();
    //     for (int i = begin; i < size; ++i) {
    //         result.push_back(nums.at(i));
    //         subsetRec(nums, result, i + 1, subSize - 1);
    //         result.pop_back();
    //     }
    // }
};
// @lc code=end