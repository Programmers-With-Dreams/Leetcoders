/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!datas.empty()){ temp.push(datas.top()); datas.pop(); }
        temp.push(x);
        while (!temp.empty()){ datas.push(temp.top()); temp.pop(); }        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() { int temp = datas.top(); datas.pop(); return temp; }
    
    /** Get the front element. */
    int peek() { return datas.top(); }
    
    /** Returns whether the queue is empty. */
    bool empty() { return datas.empty(); }
private:
    stack<int> datas;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

