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
    void flatten(TreeNode* root) {
        while(root!=NULL){
            
            TreeNode* leftSide = root->left;
            if(leftSide!=NULL){
            while(leftSide->right!=NULL){
                leftSide = leftSide->right;
            }
            }
            if(leftSide!=NULL){
                leftSide->right = root->right;
                root->right = root->left;
            }
            root->left = NULL;
            root = root->right;
            
        }
    }
};