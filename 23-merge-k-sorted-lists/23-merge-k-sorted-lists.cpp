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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = list.size();
        for(int i=0; i<n; i++)
        {
            ListNode* head = list[i];
            while(head!=NULL)
            {
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* root = NULL;
        ListNode* tail = NULL;
        while(pq.empty()==false)
        {
            if(root==NULL)
            {
                root = new ListNode(pq.top());
                tail = root;
                pq.pop();
            }
            else
            {
                tail->next = new ListNode(pq.top());
                pq.pop();
                tail = tail->next;
            }
        }
        return root;
    }
};