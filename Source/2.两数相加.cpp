/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
# include <queue>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *result, *temp = new ListNode(), *flag;
        result = temp;
        while (l1 || l2){
            int val1 = 0, val2 = 0;
            if (l1){ val1 = l1->val; l1 = l1->next; }
            if (l2){ val2 = l2->val; l2 = l2->next;}
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            temp->next = new ListNode();
            flag = temp; temp = temp->next;
        }
        if (carry){ temp->val = 1; }
        else{ flag->next = nullptr; delete temp; }
        return result;
    }
};
// @lc code=end

