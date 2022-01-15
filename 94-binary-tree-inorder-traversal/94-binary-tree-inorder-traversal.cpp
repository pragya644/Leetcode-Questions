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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while(s.empty()==false)
        {
            TreeNode*temp = s.top();
            if(temp->left!=NULL)
            {
                s.push(temp->left);
                temp->left = NULL;
            }
            else
            {
                TreeNode*t = s.top();
                res.push_back(t->val);
                s.pop();
                if(t->right!=NULL)
                    s.push(t->right);
            }
        }
        return res;
    }
};