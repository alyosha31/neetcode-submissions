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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* result = new ListNode(-1);
        ListNode* rescur = result;
        while(curr1 && curr2) {
            int addition = curr1->val + curr2->val;
            int addendum = (addition + carry);
            int value = addendum%10;
            carry = addendum/10;
            ListNode* temp = new ListNode(value);
            rescur->next = temp;
            rescur = rescur->next;
            curr1=curr1->next;
            curr2=curr2->next;
        } 
        while(curr1) {
            int addition = curr1->val;
            int addendum = (addition + carry);
            int value = addendum%10;
            carry = addendum/10;
            ListNode* temp = new ListNode(value);
            rescur->next = temp;
            rescur = rescur->next;
            curr1=curr1->next;           
        }
        while(curr2) {
            int addition = curr2->val;
            int addendum = (addition + carry);
            int value = addendum%10;
            carry = addendum/10;
            ListNode* temp = new ListNode(value);
            rescur->next = temp;
            rescur = rescur->next;
            curr2=curr2->next;           
        }
        if(carry) {
            ListNode* temp = new ListNode(carry);
            rescur->next = temp;
            rescur = rescur->next;
        }
        return result->next;
    }
};
