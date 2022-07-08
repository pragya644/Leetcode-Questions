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
    
    //brute force which is O(n^2)
    
//     bool isBST(TreeNode* root, TreeNode* mini, TreeNode*maxi)
//     {
//         if(root==NULL)
//             return true;
//         if((mini && mini->val>=root->val) || (maxi && maxi->val<=root->val))
//             return false;
//         return isBST(root->left,mini,root) && isBST(root->right,root,maxi);
//     }
    
    // optimal solution time complexity is O(n)
    
    int findMax(TreeNode* root, int &ans, int &maxi, int &mini)
    {
        if(root==NULL)
            return 0;
        int lmax = INT_MIN, rmax = INT_MIN;
        int lmin = INT_MAX, rmin = INT_MAX;
        int left = findMax(root->left,ans, lmax, lmin);
        int right = findMax(root->right,ans, rmax, rmin);
        int sum = left+right+root->val;
        if(lmax<root->val && rmin>root->val){
            ans = max(ans, sum);
            maxi = max(root->val, rmax);
            mini = min(root->val, lmin);
        }
        else
        {
            maxi = INT_MAX;
            mini = INT_MIN;
        }
        return sum;
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int Normalsum = findMax(root,ans,maxi, mini);
        return ans;
    }
};