/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // DFS 解法 
        // stack<int> graphStack;
        // size_t size = isConnected.size(), count = 0;
        // vector<bool> isVisited(size, false);
        // for (size_t i = 0; i < size; ++i) {
        //     if (isVisited.at(i)) { continue; }
        //     ++count;
        //     graphStack.push(i); // 看了好久找出的 bug
        //     while (!graphStack.empty()) {
        //         int temp_index = graphStack.top();
        //         isVisited.at(temp_index) = true;
        //         graphStack.pop();
        //         for (size_t i = 0; i < size; ++i) {
        //             if (i == temp_index) { continue; }
        //             if (isConnected.at(temp_index).at(i) == 1) {
        //                 isConnected.at(temp_index).at(i) = 2;
        //                 isConnected.at(i).at(temp_index) = 2;
        //                 graphStack.push(i);
        //             }
        //         }
        //     }
        // } 
        // return count;

        // 并查集解法
        int size = isConnected.size(), count = 0;
        vector<int> parent, layout;
        for (int i = 0; i < size; ++i) { parent.push_back(-1); layout.push_back(0); }
        for (int i = 0; i < size; ++i) { for (int j = i + 1; j < size; ++j) { 
            if (isConnected[i][j] == 1) { unionGraph(parent, layout, i, j); } } }
        for (auto &item : parent) { if (item == -1) { ++count; } }
        return count;
    }
private:
    int getRoot(vector<int> &parent, int index) {
        while(parent[index] != -1){ index = parent[index]; }
        return index;
    }
    void unionGraph(vector<int> &parent, vector<int> &layout,  int i, int j) {
        int i_root = getRoot(parent, i), j_root = getRoot(parent, j);
        if (i_root == j_root && i_root != -1) { return; }
        if (layout[i_root] < layout[j_root]) { parent[i_root] = j_root; }
        else if (layout[j_root] < layout[i_root]) { parent[j_root] = i_root; }
        else { parent[i_root] = j_root; ++layout[j_root]; }       
    }
};
// @lc code=end

