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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* curr = head;
        int i = 0;
        ListNode* prev;
        while(curr && i<k) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        ListNode* newHead = head;
        if(prev) newHead = prev;
        curr = head;
        prev = NULL;
        while(curr) {
            if(st.size() == k) {
                ListNode* temp = st.top();
                st.pop();
                if(prev) prev->next=temp;
                while(!st.empty()) {
                    temp->next = st.top();
                    temp=temp->next;
                    st.pop();
                }
                prev= temp;
                prev->next=curr;
            }
            st.push(curr);
            curr = curr->next;
        }
        if(st.size() == k) {
            ListNode* temp = st.top();
            st.pop();
            if(prev) prev->next = temp;
            while(!st.empty()) {
                temp->next = st.top();
                temp=temp->next;
                st.pop();
            }
            prev = temp;
            prev->next=curr;
        }
        return newHead;
    }
};
