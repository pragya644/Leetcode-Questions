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
    ListNode*reverse(ListNode* head,int k)
    {
        ListNode* tail = head;
        int i = 0;
        ListNode*prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        while(i<k)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        tail->next = curr;
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        ListNode* ans = head, *store = head;
        ListNode* curr = head, *node = NULL;
        int n = count/k;
        if(n==0 || k==1)
            return head;
        for(int i=0; i<n; i++)
        {
            ListNode*prev = NULL, *left = NULL;
            int j = 0;
            store = curr;
            while(j<k)
            {
                left = curr->next;
                curr->next = prev;
                prev = curr;
                curr = left;
                j++;
            }
            if(i>0)
                node->next = prev;
            else
                ans = prev;
            node = store;
        }
        node->next = curr;
        return ans;
    }
};