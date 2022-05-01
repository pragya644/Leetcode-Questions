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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int i = n-1, j=n-1;
        TreeNode* root = new TreeNode(postorder[n-1]);
        i--;
        TreeNode* temp = root;
        stack<TreeNode*> s;
        s.push(root);
        int flag = 0;
        while(i>=0)
        {
            if(s.empty()==false && s.top()->val == inorder[j])
            {
                flag = 1;
                temp = s.top();
                s.pop();
                j--;
            }
            else
            {
                if(flag==0)
                {
                    temp->right = new TreeNode(postorder[i]);
                    temp = temp->right;
                    i--;
                    s.push(temp);
                }
                else
                {
                    temp->left = new TreeNode(postorder[i]);
                    temp = temp->left;
                    i--;
                    s.push(temp);
                    flag = 0;
                }
            }
        }
        return root;
    }
};