/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
#include<stack>
using namespace std;
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // 递归解法
        // if (!root) { return sum; }
        // if (low <= root->val && root->val <= high) { sum += root->val; }        
        // if (low < root->val) { rangeSumBST(root->left, low, high); }
        // if (root->val < high) { rangeSumBST(root->right, low, high); }
        // return sum;

        // 迭代解法
        stack<TreeNode *> treeNodeStack; treeNodeStack.push(root); int sum = 0;
        while (!treeNodeStack.empty()){
            TreeNode *currNode = treeNodeStack.top(); treeNodeStack.pop();
            if (low <= currNode->val && currNode->val <= high) { sum += currNode->val; }
            if (currNode->left  && low < currNode->val ) { treeNodeStack.push(currNode->left ); }
            if (currNode->right && currNode->val < high) { treeNodeStack.push(currNode->right); }
        }
        return sum;
    }
// private:;
//     int sum = 0;
};
// @lc code=end

