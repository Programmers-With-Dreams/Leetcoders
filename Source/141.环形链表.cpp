/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode *> data;
        // while (head != nullptr){
        //     if (!data.insert(head).second){ return true; }
        //     head = head->next;          
        // }
        // return false;

        // int n = 0;
        // while (head){
        //     if(n > 10001){ return true; }
        //     head = head->next;
        //     ++n;
        // }
        // return false;

        if(!(head && head->next)){ return false; }
        ListNode *slow = head, *fast = head->next;
        while (slow != fast){
            if (!(fast && fast->next)){ return false; }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end

