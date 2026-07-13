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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* curr = newHead;
        while(l1 && l2) {
            if(l1->val<=l2->val) {
                curr->next = l1;
                l1=l1->next;
            }
            else {
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        while(l1) {
            curr->next = l1;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2) {
            curr->next = l2;
            l2=l2->next;
            curr=curr->next;
        }
        return newHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() ==0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* result = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            result = merge2Lists(result, lists[i]);
        } 
        return result;
    }
};
