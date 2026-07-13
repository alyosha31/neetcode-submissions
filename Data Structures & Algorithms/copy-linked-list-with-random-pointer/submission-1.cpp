/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        // interleave approach
        Node* curr = head;
        while(curr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr= curr->next->next;
        }
        curr = head;
        while(curr) {
            curr->next->random = curr->random? curr->random->next:NULL;
            curr = curr->next->next;
        }
        Node* newList = head->next;
        curr = newList;
        Node* curr2 = head;
        while(curr2) {
            curr2->next = curr2->next->next;
            curr2=curr2->next;
            if(curr->next)
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return newList;
    }
};
