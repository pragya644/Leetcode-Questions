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
    vector<TreeNode*> solve(int n)
    {
        if(n==1)
            return {new TreeNode()};
        vector<TreeNode*> ans;
        n--;
        vector<TreeNode*> left, right;
        for(int i=1; i<n; i += 2)
        {
            left = solve(i);
            right = solve(n-i);
        
        for(TreeNode*j: left)
        {
            for(TreeNode*k: right)
            {
                TreeNode* root = new TreeNode();
                root->left = j;
                root->right = k;
                ans.push_back(root);
            }
        }
      }
        return ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1)
            return {new TreeNode()};
        if(n%2==0)
            return {};
        // if(n==3)
        //     return {new TreeNode(), new TreeNode(), new TreeNode()};
        return solve(n);
        
    }
};