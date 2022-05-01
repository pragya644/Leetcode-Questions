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
    int sum = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = max(solve(root->left), 0);
        int right = max(solve(root->right),0);
        sum = max(sum, left+right+root->val);
        return root->val+max(left,right);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = solve(root);
        return sum;
    }
};