/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include<queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        main_queue = new queue<int>;
        sub_queue = new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        sub_queue->push(x);
        size_t size = main_queue->size();
        for (size_t i = 0; i < size; i++){
            sub_queue->push(main_queue->front());
            main_queue->pop();
        }
        swap(main_queue, sub_queue);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = top();
        main_queue->pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() { return main_queue->front(); }
    
    /** Returns whether the stack is empty. */
    bool empty() { return main_queue->empty(); }

private:
    queue<int> *main_queue;
    queue<int> *sub_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

