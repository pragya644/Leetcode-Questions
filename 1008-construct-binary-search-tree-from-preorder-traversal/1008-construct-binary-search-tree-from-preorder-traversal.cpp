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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<TreeNode* > s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i=1; i<n; i++)
        {
            if(s.empty()==false && preorder[i]<s.top()->val)
            {
                auto temp = s.top();
                temp->left = new TreeNode(preorder[i]);
                s.push(temp->left);
            }
            else
            {
                TreeNode* temp = s.top();
                while(s.empty()==false && s.top()->val<preorder[i])
                {
                    temp = s.top();
                    s.pop();
                }
                temp->right = new TreeNode(preorder[i]);
                s.push(temp->right);
            }
        }
        return root;
    }
};