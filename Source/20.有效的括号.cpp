/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> data;
        for (auto &c : s){
            if (data.empty()){ data.push(c); continue; }
            char top = data.top();
            if ((top == '(' && c == ')') || 
                (top == '{' && c == '}') ||
                (top == '[' && c == ']')){
                    data.pop();
            }
            else{ data.push(c); }
        }
        return data.empty();
    }
};
// @lc code=end

