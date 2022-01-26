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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* even = temp->next;
        ListNode* prev = NULL;
        int count = 1;
        while(temp->next!= NULL && temp!=NULL)
        {
            ListNode* curr = temp->next;
            temp->next = temp->next->next;
            prev = temp;
            temp = curr;
            count++;
        }
        if(count%2!=0)
           temp->next = even;
        else
        {
            temp->next = NULL;
            prev->next = even;
        }
        return head;
    }
};