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
    void solve(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
    }
    
    void flatten(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        TreeNode* temp = root;
        for(int i=1; i<v.size(); i++)
        {
            TreeNode* node = new TreeNode(v[i]);
            temp->left = NULL;
            temp->right = node;
            temp = temp->right;
        }
    }
};