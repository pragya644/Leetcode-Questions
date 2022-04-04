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
    int count_nodes(ListNode* head)
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
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 ;
        ListNode* temp2;
        ListNode* curr = head;
        int count = count_nodes(head);
        int k2 = count-k;
        while(curr!=NULL && k-1>0)
        {
            curr = curr->next;
            k--;
        }
        temp1 = curr;
        curr = head;
        while(curr!=NULL && k2>0)
        {
            curr = curr->next;
            k2--;
        }
        temp2 = curr;
        int value = temp1->val;
        temp1->val = temp2->val;
        temp2->val = value;
        return head;
    }
};