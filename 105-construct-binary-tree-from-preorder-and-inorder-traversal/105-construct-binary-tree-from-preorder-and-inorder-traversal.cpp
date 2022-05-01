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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        stack<TreeNode*> s;
        int i=0,j=0;
        int flag = 0;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        TreeNode* temp = root;
        s.push(root);
        while(i<n)
        {
            if(s.empty()==false && s.top()->val==inorder[j])
            {
                temp = s.top();
                s.pop();
                flag = 1;
                j++;
            }
            else
            {
                if(flag==0)
                {
                    temp->left = new TreeNode(preorder[i]);
                    temp = temp->left;
                    s.push(temp);
                    i++;
                }
                else
                {
                    flag = 0;
                    temp->right = new TreeNode(preorder[i]);
                    temp = temp->right;
                    s.push(temp);
                    i++;
                }
            }
        }
        return root;
    }
};