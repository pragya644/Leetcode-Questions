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
        if(head==NULL)
            return NULL;
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random!=NULL){
               temp->next->random = temp->random->next;
            }else{
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }
        Node* newHead = head->next;
        temp = head;
        Node* newTemp = newHead;
        while(newTemp->next!=NULL){
            temp->next = temp->next->next;
            temp = temp->next;
            newTemp->next = newTemp->next->next;
            newTemp = newTemp->next;
        }
        temp->next = NULL;
        newTemp->next = NULL;
        return newHead;
    }
};