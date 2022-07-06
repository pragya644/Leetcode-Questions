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
    
    TreeNode* solve(int&i,int l,int r,vector<int>&preorder,unordered_map<int,int> &m)
    {
        if(l>r)
            return NULL; 
        TreeNode* root = new TreeNode(preorder[i]);
        int inorderIdx = m[preorder[i]];
        i++;
        root->left = solve(i,l,inorderIdx-1,preorder,m);
        root->right = solve(i,inorderIdx+1, r, preorder,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++)
        {
            m[inorder[i]] = i;
        }
        int idx = 0;
        return solve(idx,0,n-1,preorder,m);
    }
};