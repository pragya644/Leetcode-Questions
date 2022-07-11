/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void pushLeftRight(TreeNode* curr, queue<TreeNode*> &q)
    {
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int n = q.size();
            for(int i=0; i<n-1; i++)
            {
                auto curr = q.front();
                q.pop();
                pushLeftRight(curr,q);
            }
            auto curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            pushLeftRight(curr,q);
        }
        return ans;
    }
};