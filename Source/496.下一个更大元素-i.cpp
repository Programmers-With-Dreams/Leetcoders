/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<vector>
#include<stack>
#include<map>
// #include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_vector;
        // for (auto iter1 = nums1.begin(); iter1 != nums1.end(); ++iter1){
        //     auto iter2 = find_if( find(nums2.cbegin(), nums2.cend(), *iter1), 
        //     nums2.cend(), [iter1](const int num){ return *iter1 < num; });
        //     if (iter2 == nums2.end()){ result.push_back(-1); }
        //     else{ result.push_back(*iter2); }
        // }
        // return result;
        stack<int> temp_stack;
        map<int, int> result_map;
        for (auto iter = nums2.begin(); iter != nums2.end(); ++iter){
            // iter -> value, stack -> key
            while (!temp_stack.empty() && temp_stack.top() < *iter){
                result_map[temp_stack.top()] = *iter;
                temp_stack.pop();
            }
            temp_stack.push(*iter);
        }
        while (!temp_stack.empty()){
            result_map[temp_stack.top()] = -1; 
            temp_stack.pop();
        }        
        for (auto iter = nums1.begin(); iter != nums1.end(); ++iter){
            result_vector.push_back(result_map[*iter]);
        }
        return result_vector;
    }
};
// @lc code=end

