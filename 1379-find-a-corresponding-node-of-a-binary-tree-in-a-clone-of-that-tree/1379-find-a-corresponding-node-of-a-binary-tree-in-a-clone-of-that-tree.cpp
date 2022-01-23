/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode*root1, TreeNode*root2,TreeNode* target,TreeNode* &ans )
    {
      if(root1==NULL)
          return;
      if(root1==target){
         ans = root2;
         return;
      }
      solve(root1->left, root2->left, target,ans);
      solve(root1->right, root2->right, target,ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode*ans=NULL;
        solve(original,cloned,target,ans);
        return ans;
    }
};