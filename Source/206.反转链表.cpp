/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// #include<stack>
// using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head){ return nullptr;}
        stack<ListNode *> list;
        while (head){ list.push(head); head = head->next; }
        ListNode *header = list.top();
        while (true){
            ListNode *temp = list.top();
            list.pop();
            if (list.size()){ temp->next = list.top(); }
            else{ temp->next = nullptr; break; }
        }
        return header;
    }
};
// @lc code=end

