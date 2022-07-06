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
    
    int pathSum(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return 0;
        int left = pathSum(root->left, ans);
        int right = pathSum(root->right, ans);
        ans = max(ans, root->val + left+right);
        ans = max(ans, root->val);
        ans = max(ans, root->val + left);
        ans = max(ans, root->val + right);
        return max(root->val, root->val + max(left,right));
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int value = pathSum(root,ans);
        return ans;
    }
};