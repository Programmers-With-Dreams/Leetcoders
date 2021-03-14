/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) { return results; }
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            int size = treeQueue.size();
            results.push_back(vector<int> ());
            for (int i = 0; i < size; ++i) {
                TreeNode *temp = treeQueue.front(); treeQueue.pop();
                if (temp->left ) { treeQueue.push(temp->left ); }
                if (temp->right) { treeQueue.push(temp->right); }
                results.back().push_back(temp->val);
            }
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
// @lc code=end

