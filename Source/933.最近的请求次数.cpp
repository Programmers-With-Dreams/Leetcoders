/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
#include<queue>
using namespace std;
class RecentCounter {
public:
    int ping(int t) {
        data.push(t);
        while (data.front() < t - 3000 ){ data.pop(); }
        return data.size();
    }
private:
    queue<int> data;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

