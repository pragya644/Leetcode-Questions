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


                                                                      // 7 3 2 1 Null
//                                                                    // 7 3 2 1
//                                                      1st iteration  7->7->3->3->2->2->1->1->null
//                                                                    0  c  0  c  0  c  0  c
//                                                                    3->random = 7
//                                                     2nd iteration  3->next->random = 3->random->next
//                                                                    3(o)->3(c)->random = 3(o)->7(o)->7(c);
//                                                     3rd iteraton   1 (ans node)
//                                                                    1 (helper node)
//                                                                    helper->next = head->next
//                                                                    1->next = 7(o)->7(c)   
//                                                                    1->next = 7(c)
//                                                                    head->next = head->next->next
//                                                                    7(o)->next = 7(o)->7(c)->3(o)
//                                                                    head = head->next
//                                                                   head = 7(o)->3;
                                                                   
//                                                     return         ans->next;

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