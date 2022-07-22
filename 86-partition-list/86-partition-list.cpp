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
        ListNode* newHead = NULL;
        ListNode* tempNew = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val < x && newHead == NULL){
                newHead = new ListNode(temp->val);
                tempNew = newHead;
            }else if(temp->val < x){
                tempNew->next = new ListNode(temp->val);
                tempNew = tempNew->next;
            }
            temp = temp->next;
        }
        ListNode* temp2 = head;
        ListNode* greaterHead = NULL;
        ListNode* tempgreater;
        while(temp2!=NULL){
            if(temp2->val >= x && greaterHead == NULL){
                greaterHead = new ListNode(temp2->val); 
                tempgreater = greaterHead;
            }else if(temp2->val >= x){
                tempgreater->next = new ListNode(temp2->val);
                tempgreater = tempgreater->next;
            }
            temp2 = temp2->next;
        }
        if(tempNew!=NULL){
            tempNew->next = greaterHead;
            return newHead;
        }
        return greaterHead;
    }
};