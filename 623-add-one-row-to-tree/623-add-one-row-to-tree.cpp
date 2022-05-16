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
    void add(TreeNode* root, int val)
    {
        if(root->left==NULL)
            root->left = new TreeNode(val);
        else 
        {
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp;
        }
        if(root->right==NULL)
            root->right = new TreeNode(val);
        else
        {
            TreeNode* temp = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp;
        }
    }
    
    void solve(TreeNode* root, int curr, int val, int d)
    {
        if(root==NULL)
            return;
        if(curr == d-1)
        {
            add(root,val);
            return;
        }
        solve(root->left,curr+1,val,d);
        solve(root->right,curr+1,val,d);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* temp = root;
            root = new TreeNode(val);
            root->left = temp;
            return root;
        }
        solve(root,1,val,depth);
        return root;
    }
};
