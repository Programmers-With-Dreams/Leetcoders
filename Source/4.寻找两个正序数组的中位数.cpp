/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        int full_size = nums1.size() + nums2.size();
        vector<int> temp;
        auto iter1 = nums1.begin(), iter2 = nums2.begin();
        while (iter1 != nums1.end() || iter2 != nums2.end()){
            if (iter1 == nums1.end()){ temp.push_back(*iter2++); continue; }
            if (iter2 == nums2.end()){ temp.push_back(*iter1++); continue; }
            temp.push_back(*iter1 < *iter2 ? *iter1++ : *iter2++);
        }
        if (full_size % 2 == 0){
            result = (temp.at(full_size / 2) + temp.at(full_size / 2 - 1)) / 2.0;
        }
        else{ result = temp.at(full_size / 2); }
        return result;
    }
};
// @lc code=end

