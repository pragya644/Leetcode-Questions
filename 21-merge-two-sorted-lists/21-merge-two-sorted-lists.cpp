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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = NULL;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* tail = root;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val <= temp2->val)
            {
                if(root==NULL){
                    root = temp1;
                    tail = root;
                }
                else{
                    tail->next = temp1;
                    tail = tail->next;
                }
                temp1 = temp1->next;
            }
            else
            {
                if(root==NULL){
                    root = temp2;
                    tail = root;
                }
                else{
                    tail->next = temp2;
                    tail = tail->next;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1!=NULL)
        {
            if(root==NULL){
                root = temp1;
                tail = root;
            }
            else{
               tail->next = temp1;
               tail = tail->next;
            }
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            if(root==NULL){
                root = temp2;
                tail = root;
            }
            else{
              tail->next = temp2;
              tail = tail->next;
            }
            temp2 = temp2->next;
        }
        return root;    
    }
};