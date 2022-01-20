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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        int count = k;
        while(!s.empty() || root)
        {
            while(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode*temp = s.top();
            s.pop();
            count--;
            if(count==0)
                return temp->val;
            root = temp->right;
        }
        return 0;
    }
};