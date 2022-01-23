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
    void solve(TreeNode*root, int &curr)
    {
        if(root==NULL)
            return;
        solve(root->right, curr);
        root->val += curr;
        curr = root->val;
        solve(root->left, curr);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int curr = 0;
        solve(root,curr);
        return root;
    }
};