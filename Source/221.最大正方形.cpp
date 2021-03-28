/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // square[i,j] = min{square[i - 1,j], square[i - 1,j - 1], square[i,j - 1]} + 1
        int sizeR = matrix.size(), sizeC = matrix.at(0).size(), maxSquare = 0;
        vector<int> temp(sizeC + 1, 0);
        vector<vector<int>> square(sizeR + 1, temp);
        for (int i = 0; i < sizeR; ++i) {
            for (int j = 0; j < sizeC; ++j) {
                if (matrix[i - 1][j - 1] == '0') { square[i][j] = 0; continue; }
                int min = square[i - 1][j - 1];
                if (square[i - 1][j] < min) { min = square[i - 1][j]; }
                if (square[i][j - 1] < min) { min = square[i][j - 1]; }
                square[i][j] = ++min;
                if(maxSquare < min) { maxSquare = min; }
            }
        }
        return maxSquare*maxSquare;
    }
};
// @lc code=end

