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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp=temp->next;
        }
        if(size==1 && n == 1) return NULL;
        //node from the front to be removed
        int t = size-n;
        if(t==0) {
            return head->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        int i = 0;
        while(curr && i<t) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(curr)
        prev->next = curr->next;
        return head;
    }
};
