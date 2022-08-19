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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> rightViewNodes;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int size = q.size();
            while(size>0){
                auto curr = q.front();
                q.pop();
                if(size==1){
                    rightViewNodes.push_back(curr->val);
                }
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                size--;
            }
        }
        return rightViewNodes;
    }
};