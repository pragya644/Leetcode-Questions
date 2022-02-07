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
    int countnode(ListNode* head)
    {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* temp = head;
        int count = 1;
        while(temp->next!=NULL)
        {
            count++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%count;
        ListNode* node = head;
        int n = count-k-1;
        while(n>0)
        {
            node = node->next;
            n--;
        }
        ListNode* first = node->next;
        node->next = NULL;
        return first;
    }
};