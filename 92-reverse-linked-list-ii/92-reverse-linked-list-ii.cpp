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
    
    ListNode* reverseLeftRight(ListNode* &left,ListNode* &right){
        ListNode* prev = NULL;
        ListNode* curr = left;
        ListNode* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode* currPos = head;
        ListNode* leftSideNodes;
        ListNode* rightSideNodes;
        ListNode* leftNode;
        ListNode* rightNode;
        int pos = 1;
        if(pos == left){
            leftSideNodes = NULL;
            leftNode = head;
        }
        while(currPos!=NULL){
            if(pos+1 == left){
                leftSideNodes = currPos;
                leftNode = currPos->next;
                break;
            }
            currPos = currPos->next;
            pos++;
        }
        
        currPos = head;
        pos = 1;
        while(currPos!=NULL){
            if(pos == right){
                rightSideNodes = currPos->next;
                rightNode = currPos;
                break;
            }
            currPos = currPos->next;
            pos++;
        }
        
        rightNode->next = NULL;
        ListNode* revHead = reverseLeftRight(leftNode,rightNode);
        if(leftSideNodes!=NULL){
            leftSideNodes->next = revHead;
        }else{
            head = revHead;
        }
        
        leftNode->next = rightSideNodes;
        return head;
    }
};