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
		sort(coins.begin(), coins.end(), [](int a, int b)->bool { return a > b; });
		if (amount == 0) { return 0; }
		else { return coinRec(coins, amount, coins.begin() + 1); }
	}
private:
	int coinRec(vector<int> &coins, int left, vector<int>::iterator begin) {
		if (left < 0) { return -1; }
		if (left == 0) { return 0; }
		auto currMax = upper_bound(begin, coins.end(), left, [](int a, int b)->bool { return a >= b; });
		while (currMax != coins.end()) {
			cout << left << " " << *currMax << endl;
			int count = coinRec(coins, left - *currMax, currMax);
			switch (count) {
			case -1: continue; break;
			case  0: return 1;
			default: return ++count; break;
			}
			++currMax;
		}
		return -1;
	}
};
// @lc code=end


// [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
int main() {
	Solution solution;
	vector<int> demo{ 28, 15, 1 };
	cout << solution.coinChange(demo, 30);
}