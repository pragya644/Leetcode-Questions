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
    
    void solve(TreeNode* root, unordered_map<int,int> &m)
    {
        if(root==NULL)
            return;
        m[root->val]++;
        solve(root->left,m);
        solve(root->right,m);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> m;
        solve(root,m);
        for(auto x: m)
        {
            int diff = k-x.first;
            if(diff==0)
                continue;
            if(diff!=x.first && m.find(diff)!=m.end())
                return true;
            else if(diff==x.first)
            {
                if(m[diff]>1)
                    return true;
            }
        }
        return false;
    }
};