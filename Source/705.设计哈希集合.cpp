/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
#include<array>
using namespace std;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() { length = 10007; for (auto &item : datas) { item = -1; } }
    
    void add(int key) { datas.at(search(key)) = key; }
    
    void remove(int key) { datas.at(search(key)) = -2; } //由于remove，可能导致中间会出现空槽
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (datas.at(search(key)) < 0) { return false; }
        else { return true; }
    }

private:
    array<int, 10007> datas;
    int length = 10007;
    int hash(int key) { return ((key * 2 + 1 + length) % length); }
    int search(int key) {
        int hash_value = hash(key), flag = 1, mul = 1, index = hash_value;
        while (datas.at(index) != -1) {
            if(datas.at(index) == key) { return index; }
            index = (hash_value + flag * mul + length) % length;
            if (flag == -1) { ++mul; }
            flag *= -1;
        }
        return index;
    }   // 查找失败返回下一个空位置的 index
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

