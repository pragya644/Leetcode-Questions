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
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
        temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->random)
               temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* copy = new Node(0);
        Node* dummy_Node = copy;
        while(head!=NULL && head->next!=NULL)
        {
            dummy_Node->next = head->next;
            dummy_Node = dummy_Node->next;
            head->next = head->next->next;
            head = head->next;
        }
        return copy->next;
    }
};