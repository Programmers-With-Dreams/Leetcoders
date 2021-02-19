/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_multiset<int> datas;
        // for (auto &c : s){ datas.insert(c); }
        // for (auto &c : t){
        //     auto iter = datas.find(c);
        //     if (iter == datas.cend()){ return c; }
        //     datas.erase(iter);
        // }
        // return *datas.begin();
        char result = 0;
        for (auto &c : s + t){ result ^= c; }
        return result;
    }
};
// @lc code=end

