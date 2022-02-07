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
        unordered_map<Node*, Node*> m;
        m.insert({NULL, NULL});
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            m[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            Node* copy = m[temp];
            copy->next = m[temp->next];
            copy->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};