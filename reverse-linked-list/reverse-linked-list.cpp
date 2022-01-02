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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        while(head!=NULL)
        {
            temp = prev;
            prev = head;
            head = head->next;
            prev->next = temp;
        }
        return prev;
    }
};