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
    bool hasCycle(ListNode* head) {
        //rabbit and hare method if i remember correctly
        if(head == NULL or head->next == NULL) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=NULL) {
            if(slow == fast) return true;
            slow = slow->next;
            if(fast->next != NULL && fast->next->next != NULL)
            fast = fast->next->next;
            else return false;
        }
        return false;
    }
};
