/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int height(ListNode *head)
    {
        ListNode * temp = head;
        int ans = 0;
        while(temp!=NULL)
        {
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ha = height(headA);
        int hb = height(headB);
        ListNode *tempa = headA;
        ListNode *tempb = headB;
        if(ha>hb)
        {
            int d = ha-hb;
            while(d--)
               tempa = tempa->next;
        }
        else
        {
            int d = hb-ha;
            while(d--)
                tempb = tempb->next;
        }
        while(tempa!=NULL && tempb!=NULL && tempa!=tempb)
        {
            tempa = tempa->next;
            tempb = tempb->next;
        }
        return tempa;
    }
};