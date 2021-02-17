/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k;
        datas = new int[k];
        for (int i = 0; i < k; i++){ datas[i] = -1; }
    }

    ~MyCircularDeque(){ delete [] datas; }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()){ return false; }
        if (!isEmpty()){ headIndex = (--headIndex + capacity) % capacity; }
        datas[headIndex] = value;
        ++size;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()){ return false; }
        if (!isEmpty()){ tailIndex = ++tailIndex % capacity; }
        datas[tailIndex] = value;
        ++size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()){ return false; }
        datas[headIndex] = -1;
        if (size > 1){ headIndex = ++headIndex % capacity; }
        --size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()){ return false; }
        datas[tailIndex] = -1;
        if (size > 1){ tailIndex = (--tailIndex + capacity) % capacity; }
        --size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() { return datas[headIndex]; }
    
    /** Get the last item from the deque. */
    int getRear() { return datas[tailIndex]; }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() { return !size; }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() { return size == capacity; }

private:
    int *datas;
    int size = 0, capacity;
    int headIndex = 0, tailIndex = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

