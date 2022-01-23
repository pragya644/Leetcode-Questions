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
    int height(TreeNode* root)
    {
        if(root== NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int h = height(root)-2;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(h>0 && q.empty()==false)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                TreeNode*temp = q.front();
                q.pop();
                int x = temp->val;
                if(x%2==0)
                {
                    if(temp->left!=NULL && temp->left->left!=NULL)
                        ans += temp->left->left->val;
                    if(temp->left!=NULL && temp->left->right!=NULL)
                        ans += temp->left->right->val;
                    if(temp->right!=NULL && temp->right->left!=NULL)
                        ans += temp->right->left->val;
                    if(temp->right!=NULL && temp->right->right!=NULL)
                        ans += temp->right->right->val;
                }
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            h--;
        }
        return ans;
    }
};