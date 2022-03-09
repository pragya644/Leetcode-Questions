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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        ListNode*temp = head;
        ListNode*start,*end;
        ListNode*prev = NULL;
        while(temp!=NULL)
        {
            start = temp;
            int x = temp->val;
            while(temp!=NULL && x==temp->val)
            {
                end = temp;
                temp = temp->next;
            }
            if(start!=end)
            {
                if(prev==NULL)
                {
                    head = temp;
                }
                else
                {
                    prev->next = temp;
                }
            }
            else
               prev = start;
        }
        return head;
    }
};