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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        ListNode* head = newList;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                newList->next = l1;
                l1=l1->next;
            }
            else {
                newList->next = l2;
                l2=l2->next;
            }
            newList=newList->next;
        }
        while(l1 != NULL) {
            newList->next = l1;
            l1=l1->next;
            newList=newList->next;
        }
        while(l2 != NULL) {
            newList->next = l2;
            l2=l2->next;
            newList=newList->next;
        }
        return head->next;
    }
};
