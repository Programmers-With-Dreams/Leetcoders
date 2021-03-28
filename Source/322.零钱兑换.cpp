/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 贪心 + 剪枝
        // if (amount == 0) { return 0; }
        // sort(coins.rbegin(), coins.rend());
        // int minCount = -1;
        // coinRec(coins, amount, minCount, 0, 0);
        // return minCount;

        // 动态规划
        // F(amount) = min{F(amount - coins[i])} + 1
        if (amount == 0) { return 0; }
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int size = coins.size();
        for (int a = 1; a <= amount; ++a) {
            for (int i = 0; i < size; ++i) {
                if (a < coins.at(i)) { break; }
                else {dp[a] = min(dp[a], dp[a - coins.at(i)]);}
            }
            ++dp[a];
        }
        return dp.at(amount) > amount ? -1 : dp.at(amount);
    }
// private:
//     void coinRec(vector<int> &coins, int leftAmount, int &minCount, int currCount, int index) {
//         if (leftAmount == 0) { 
//             if (minCount == -1) { minCount = currCount; }
//             else if (currCount < minCount) { minCount = currCount; }
//             return;
//         }
//         if ((minCount != -1 && minCount <= currCount) || index == coins.size()) { return; }
//         for (int itemCount = (leftAmount/coins[index]); itemCount >= 0; --itemCount) {
//             coinRec(coins, leftAmount - itemCount*coins[index], minCount, currCount + itemCount, index + 1);
//         }
//     }
};
// @lc code=end