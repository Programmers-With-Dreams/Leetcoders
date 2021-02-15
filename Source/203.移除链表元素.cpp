/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *header = new ListNode;
        header->next = head;
        ListNode *prev_pointer = header, *dele_pointer = nullptr;
        while (head){
            if(head->val == val){ 
                prev_pointer->next = head->next; 
                dele_pointer = head;
            }
            else{ prev_pointer = head; }
            head = head->next;
            if (dele_pointer){ 
                delete dele_pointer;
                dele_pointer = nullptr; 
            }
        }
        ListNode *result = header->next;
        delete header;
        return result;
    }
};
// @lc code=end

