/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    MyCircularQueue(int k) { 
        data = new int[k];
        capacity = k;
        for (int i = 0; i < k; i++){ data[i] = -1; }
    }

    ~MyCircularQueue() { delete [] data; }
    
    bool enQueue(int value) {
        if (isFull()){ return false; }
        if (!isEmpty()){ tail_position = (++tail_position) % capacity; }
        data[tail_position] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()){ return false; }
        data[head_position] = -1;
        if (size > 1){ head_position = (++head_position) % capacity;}
        --size;
        return true;
    }
    
    int Front() { return data[head_position]; }
    
    int Rear() { return data[tail_position]; }
    
    bool isEmpty() { return !size; }
    
    bool isFull() { return size == capacity; }

private:
    int *data;
    int size = 0;
    int capacity;
    int head_position = 0;
    int tail_position = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end