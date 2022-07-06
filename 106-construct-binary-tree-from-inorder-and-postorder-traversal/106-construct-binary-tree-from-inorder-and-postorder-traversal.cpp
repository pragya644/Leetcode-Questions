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
    
    TreeNode* solve(int &i, int l, int r, vector<int> &post, unordered_map<int,int> &m)
    {
        if(l>r)
            return NULL;
        int curr = m[post[i]];
        TreeNode* root = new TreeNode(post[i]);
        i--;
        root->right = solve(i,curr+1,r, post,m);
        root->left = solve(i,l, curr-1,post,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n = inorder.size();
        for(int i=0; i<n; i++)
            m[inorder[i]] = i;
        int idx = n-1;
        return solve(idx,0,n-1,postorder,m);
    }
};