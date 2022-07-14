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
    
    //time complexity is O(N) and space Complexity is O(N)
    
    TreeNode* makeTree(int &i,vector<int> &preorder,int l,int r , unordered_map<int,int> &m)
    {
        if(l>r)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int currPosInInorder = m[preorder[i]];
        i++;
        root->left = makeTree(i,preorder,l,currPosInInorder-1,m);
        root->right =  makeTree(i,preorder,currPosInInorder+1,r,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0; i<inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        int n = inorder.size();
        int i = 0;
        return makeTree(i,preorder,0,n-1,m);
    }
};