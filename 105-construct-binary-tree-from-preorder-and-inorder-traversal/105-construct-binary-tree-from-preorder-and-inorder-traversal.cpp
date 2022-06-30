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
    
    TreeNode* solve(vector<int> &p, vector<int> &i, int &rootIdx, int l, int r)
    {
        if(l>r)
            return NULL;
        int curr = l;
        while(i[curr]!=p[rootIdx])
            curr++;
        rootIdx++;
        TreeNode* root = new TreeNode(i[curr]);
        root->left = solve(p,i,rootIdx,l,curr-1);
        root->right = solve(p,i,rootIdx, curr+1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return solve(preorder,inorder,rootIdx,0,inorder.size()-1);
    }
};