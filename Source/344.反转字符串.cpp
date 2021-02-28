/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = 0, tail = s.size() - 1;
        while (head < tail){
            int temp = s.at(head); s.at(head) = s.at(tail); s.at(tail) = temp;
            ++head; --tail;
        }
    }
};
// @lc code=end

