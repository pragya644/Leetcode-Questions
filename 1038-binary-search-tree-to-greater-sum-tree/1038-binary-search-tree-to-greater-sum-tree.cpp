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
    void solve(TreeNode*root, stack<TreeNode*> &s)
    {
        if(root==NULL)
            return;
        solve(root->left, s);
        s.push(root);
        solve(root->right, s);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> s;
        solve(root,s);
        while(s.size()>1)
        {
            TreeNode*x = s.top();
            s.pop();
            TreeNode*y = s.top();
            s.pop();
            y->val += x->val;
            s.push(y);
        }
        return root;
    }
};