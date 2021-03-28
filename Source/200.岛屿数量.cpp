/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <stack>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // DFS
        // int sizeR = grid.size(), sizeC = grid.at(0).size(), number = 0;
        // for (int i = 0; i < sizeR; ++i) {
        //     for (int j = 0; j < sizeC; ++j) {
        //         if (grid.at(i).at(j) != '1') { continue; }    // 此处说明被访问了
        //         stack<pair<int, int>> islandStack;
        //         islandStack.push({i, j}); 
        //         grid[i][j] = '2';
        //         while (!islandStack.empty()) {
        //             int tempR = islandStack.top().first, tempC = islandStack.top().second;
        //             grid.at(tempR).at(tempC) = '2';
        //             islandStack.pop();
        //             if (tempR + 1 < sizeR && grid.at(tempR + 1).at(tempC) == '1') { islandStack.push({tempR + 1, tempC}); }
        //             if (tempC + 1 < sizeC && grid.at(tempR).at(tempC + 1) == '1') { islandStack.push({tempR, tempC + 1}); }
        //             if (0 <= tempR - 1 && grid.at(tempR - 1).at(tempC) == '1') { islandStack.push({tempR - 1, tempC}); }
        //             if (0 <= tempC - 1 && grid.at(tempR).at(tempC - 1) == '1') { islandStack.push({tempR, tempC - 1}); }
        //         }
        //         ++number;
        //     }
        // }
        // return number;
    }
};
// @lc code=end

