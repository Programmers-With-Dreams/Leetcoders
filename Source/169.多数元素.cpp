/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityRec(vector<int>& nums, int left, int right) {
        if (left + 1 == right) { return nums.at(left); }
        int mid = (left + right) >> 1;
        int leftMajority = 0, rightMajority = 0, LMcount = 0, RMcount = 0;
        leftMajority = majorityRec(nums, left, mid);
        rightMajority = majorityRec(nums, mid, right);
        for (int i = left; i < right; ++i) { 
            if (nums.at(i) == leftMajority) { ++LMcount; continue; }
            if (nums.at(i) == rightMajority) { ++RMcount; continue; }
        }
        return LMcount < RMcount ? rightMajority : leftMajority;
    }

    int majorityElement(vector<int>& nums) {
        // hash 法
        // unordered_map<int, int> count;
        // int result = 0, size = nums.size();
        // for (auto &item : nums){ if (++count[item] > size >> 1) { result = item; } }
        // return result;

        // 排序法
        // sort(nums.begin(), nums.end());
        // return nums.at(nums.size() >> 1);

        // 递归法
        // return majorityRec(nums, 0, nums.size());

        // Boyer-Moore 投票算法
        int candidate = nums.at(0), count = 0;
        for (auto &item : nums) {
            if (item == candidate) { ++count; }
            else if (--count == 0) { candidate = item; ++count; }
        }
        return candidate;
    }
};
// @lc code=end

