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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1!=NULL && temp2!=NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ListNode *b = headB;;
        ListNode *a = headA;;
        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                temp2 = temp2->next;
                b = b->next;
            }
        }
        else
        {
            while(temp1!=NULL)
            {
                temp1 = temp1->next;
                a = a->next;
            }
        }
        while(a!=b && a!=NULL && b!=NULL)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};