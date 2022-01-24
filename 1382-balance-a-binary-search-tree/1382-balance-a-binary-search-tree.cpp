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
    vector<TreeNode*> v;
    void inorder(TreeNode*root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    
    TreeNode* solve(int l, int r)
    {
        if(l>r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode*root = v[mid];
        root->left = solve(l,mid-1);
        root->right = solve(mid+1,r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        inorder(root);
        int n = v.size();
        root = solve(0,n-1);
        return root;
    }
};