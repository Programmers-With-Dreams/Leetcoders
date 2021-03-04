/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        max = 0; getPathByRoot(root); return max;
    }
private:
    int max;
    int getPathByRoot(TreeNode* root) {
        if (!root) { return 0; }
        int leftPath  = getPathByRoot(root->left );
        int rightPath = getPathByRoot(root->right);
        int count = 0;
        if (root->left  && root->val == root->left ->val) { count += ++leftPath; }
        else { leftPath  = 0; }
        if (root->right && root->val == root->right->val) { count += ++rightPath;}
        else { rightPath = 0; }
        if (max < count) { max = count; }
        return leftPath < rightPath ? rightPath : leftPath;
    }
};
// @lc code=end

