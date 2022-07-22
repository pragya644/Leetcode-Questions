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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        ListNode* smaller = new ListNode(0);
        ListNode* temp1 = smaller;
        ListNode* greater = new ListNode(0);
        ListNode* temp2 = greater;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                temp1->next = new ListNode(temp->val);
                temp1 = temp1->next;
            }else{
                temp2->next = new ListNode(temp->val);
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp1->next = greater->next;
        return smaller->next;
    }
};