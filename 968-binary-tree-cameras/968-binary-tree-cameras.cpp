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
    // a node can have three cases 
    // 1. Node need a camera : 1
    // 2. Node don't need a camera : -1
    // 3. Node itself a camera : 0
    
    int solve(TreeNode* root, int &count)
    {
        if(root==NULL)
            return -1;
        int left = solve(root->left, count);
        int right = solve(root->right, count);
        if(left==1 || right==1)
        {
            count++;
            return 0; 
            // here node need become a camera becuase any one or both of its child need a camera
        }
        if(left==0 || right==0)
        {
            return -1;
            // node dont't need to be a camera because one of its child will cover him
        }
        return 1;
        // means 
    }
    
    int minCameraCover(TreeNode* root) {
        int count = 0;
        int ans = solve(root, count);
        if(ans==1)
            return count+1;
        return count;
    }
};