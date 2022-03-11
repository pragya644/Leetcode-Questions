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
    int countnodes(ListNode* head)
    {
        ListNode*temp = head;
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
            return NULL;
        int count = countnodes(head);
        k = k%count;
        ListNode* temp;
        int left = count-k-1;
        ListNode* curr = head;
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next = head;   // joint the last node with the head and made it circular!
        temp = head;
        while(left!=0)
        {
            temp = temp->next;
            left--;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};