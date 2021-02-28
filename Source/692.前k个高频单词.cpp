/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 题目要求 计数从大到小排->字母从小到大排
        unordered_map<string, int> datas_map;
        for (auto &word : words) { ++datas_map[word]; }
        priority_queue<pair<int, string>> datas_heap;
        for (auto &data : datas_map) { 
            datas_heap.push({-data.second, data.first});
            if (k < datas_heap.size()) { datas_heap.pop(); }
        }   // 此时计数从小到大排->字母从大到小排
        vector<string> topKdatas;
        for (int i = 0; i < k; ++i) {
            topKdatas.push_back(datas_heap.top().second);
            datas_heap.pop();
        }
        reverse(topKdatas.begin(), topKdatas.end());    // 反过来
        return topKdatas;
    }
};
// @lc code=end

