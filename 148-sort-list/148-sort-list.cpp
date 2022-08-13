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
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* curr = new ListNode();
        ListNode* temp = curr;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }else{
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }
        
        while(left!=NULL){
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        while(right!=NULL){
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
        return curr->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode*left = sortList(head);
        ListNode* right = sortList(fast);
        return merge(left,right);
    }
};