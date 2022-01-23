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
    int height(TreeNode*root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left), height(root->right))+1;
    }
    void solve(TreeNode*root, int h, int &ans)
    {
        if(root==NULL)
            return;
        if(h==1)
           ans = ans + root->val; 
        solve(root->left , h-1 , ans);
        solve(root->right , h-1 , ans);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int ans = 0;
        solve(root, h,ans);
        return ans;
    }
};