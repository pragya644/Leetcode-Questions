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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->left==NULL || root->right==NULL)
            return false;
        q.push(root->left);
        q.push(root->right);
        while(q.empty()==false)
        {
            auto curr1 = q.front();
            q.pop();
            auto curr2 = q.front();
            q.pop();
            if(curr1->val!=curr2->val)
                return false;
            if(curr1->left!=NULL && curr2->right!=NULL)
            {
                q.push(curr1->left);
                q.push(curr2->right);
            }
            else if(!(curr1->left==NULL && curr2->right==NULL) && (curr1->left==NULL || curr2->right==NULL))
            {
                return false;
            }
            if(curr1->right!=NULL && curr2->left!=NULL)
            {
                q.push(curr1->right);
                q.push(curr2->left);
            }
            else if(!(curr1->right==NULL && curr2->left==NULL) && (curr1->right==NULL || curr2->left==NULL))
            {
                return false;
            }
                    
        }
        return true;
    }
};