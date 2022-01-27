/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* l1 = lca(root->left,p,q);
        TreeNode* l2 = lca(root->right,p,q);
        if(l1!=NULL && l2!=NULL)
            return root;
        if(l1!=NULL)
            return l1;
        else
            return l2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = lca(root,p,q);
        return ans;
    }
};