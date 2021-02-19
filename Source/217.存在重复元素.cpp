/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include<vector>
#include<algorithm>
// #include<unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> data;
        // for (auto iter = nums.begin(); iter != nums.end(); ++iter){
        //     if (data.find(*iter) != data.end()){ return true; }
        //     data.insert(*iter);
        // }
        // return false;
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) == nums.end() ? false : true;
    }
};
// @lc code=end

