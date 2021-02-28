/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<algorithm>
#include<vector>
// #include<queue>
using namespace std;
class Solution {
public:
    void heapity(vector<int>& nums, int index, int size) {
        int lc = 2 * index + 1, rc = 2 * index + 2, value = nums.at(index);
        do{
            if (size <= lc){ return; }
            else if (size == rc && value < nums.at(lc)) { 
                nums.at(index) = nums.at(lc); nums.at(lc) = value; return;
            }
            else if (rc < size && (value < nums.at(lc) || value < nums.at(rc))) {
                int max = nums.at(lc) < nums.at(rc) ? rc : lc;
                nums.at(index) = nums.at(max); nums.at(max) = value;
                index = max; lc = 2 * index + 1; rc = 2 * index + 2;
            }
            else { return; }
        } while (true);
    }

    void buildHeap(vector<int>& nums) {
        int size = nums.size();
        for (int i = (size >> 1) - 1; i >= 0; --i) { heapity(nums, i, size); }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return(nums.at(nums.size() - k));

        // priority_queue<int> data;
        // for (auto &item : nums){ data.push(item); }
        // for (int i = 0; i < k - 1; ++i) { data.pop(); }
        // return data.top();

        buildHeap(nums);
        int size = nums.size();
        for (int i = size - 1; i >= size - k + 1; --i){
            nums.at(0) = nums.at(i);
            heapity(nums, 0, i);
        }
        return nums.at(0);
    }
};
// @lc code=end

