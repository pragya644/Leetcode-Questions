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
    void solve(TreeNode* current, TreeNode*parent, TreeNode*gparent,int &ans)
    {
        if(current==NULL)
            return;
        if(gparent!=NULL && gparent->val%2==0)
            ans += current->val;
        solve(current->left, current,parent,ans);
        solve(current->right,current, parent,ans);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        solve(root,NULL,NULL,ans);
        return ans;
    }
};