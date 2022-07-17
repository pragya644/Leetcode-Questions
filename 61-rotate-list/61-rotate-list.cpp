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
    
    int findHeight(ListNode* head)
    {
        ListNode* temp = head;
        int length = 0;
        while(temp!=NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
            return head;
        int length = findHeight(head);
        k = k%length;
        if(k==0)
            return head;
        int intialLength = length - k;
        ListNode* node = head;
        while(node!=NULL && intialLength>1)
        {
            node = node->next;
            intialLength--;
        }
        ListNode* leftNode = node->next;
        node->next = NULL;
        ListNode* leftNodetemp =leftNode;
        while(leftNodetemp!=NULL && leftNodetemp->next!=NULL)
            leftNodetemp = leftNodetemp->next;
        leftNodetemp->next = head;
        return leftNode;
    }
};