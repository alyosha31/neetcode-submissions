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

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev; //head of the new reversed linked list
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL) return ;
        //finding out the middle first using fast slow approach
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* end = reverseList(slow);
        ListNode* curr = head;
        while(curr && end) {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = end->next;
            curr->next = end;
            end->next = temp1;
            curr = temp1;
            end = temp2;
        }
        
    }
};
