/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        datas = new int[10000];
    }

    ~MyHashSet() { delete [] datas; }
    
    void add(int key) {

    }
    
    void remove(int key) {

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {

    }
private:
    int *datas;
    int hash(int key);
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

