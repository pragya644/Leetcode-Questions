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
    
    TreeNode* ans;
    
    bool solve(TreeNode* root, int val)
    {
        if(root==NULL)
            return false;
        if(root->val == val){
            ans = root;
            return true;
        }
        return solve(root->left, val) || solve(root->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        bool flag = solve(root,val);
        if(flag==false)
            return NULL;
        return ans;
    }
};