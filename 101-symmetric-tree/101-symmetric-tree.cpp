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
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        if(root->left==NULL || root->right==NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.empty()==false)
        {
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();
            if(l==NULL && r==NULL)
                continue;
            if(l==NULL || r==NULL)
                return false;
            if(l->val!=r->val)
                return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};