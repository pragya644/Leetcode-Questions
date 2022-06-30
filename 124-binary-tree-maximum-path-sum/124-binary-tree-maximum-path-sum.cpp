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
    
    int solve(TreeNode* root, int &sum)
    {
        if(root==NULL)
            return 0;
        int l = max(solve(root->left,sum),0);
        int r = max(solve(root->right,sum), 0);
        int temp_sum = l+r+root->val;
        sum = max(sum, temp_sum);
        return root->val+ max(l,r);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root,sum);
        return sum;
    }
};