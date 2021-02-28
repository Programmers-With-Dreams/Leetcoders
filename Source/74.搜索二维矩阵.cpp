/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size_row = matrix.size(), size_column = matrix.at(0).size();
        int begin = 0, end = size_row * size_column, mid = (begin + end) >> 1;
        // (mid / size_column, mid % size_column)
        while (begin + 1 != end){
            if (matrix.at(mid / size_column).at(mid % size_column) <= target){ 
                begin = mid;
            }
            else { end = mid; }
            mid = (begin + end) >> 1;
        }
        if (matrix.at(begin / size_column).at(begin % size_column) == target){ 
            return true;
        }
        return false;
    }
};
// @lc code=end