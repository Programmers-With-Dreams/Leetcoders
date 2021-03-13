/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        combineRec(temp, 1, k, n);
        return result;
    }

private:
    vector<vector<int>> result;
    void combineRec(vector<int> &nums, int begin, int k, int n) {
        if (!k) { result.push_back(nums); return; }
        for (int i = begin; i <= n; i++){
            nums.push_back(i);
            combineRec(nums, i + 1, k - 1, n);
            nums.pop_back();
        }
    }    
};
// @lc code=end

