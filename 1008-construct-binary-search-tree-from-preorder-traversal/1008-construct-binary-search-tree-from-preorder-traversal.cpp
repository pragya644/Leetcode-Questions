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
    TreeNode* bstFromPreorder(vector<int>& p) {
        int n = p.size();
        TreeNode* root = new TreeNode(p[0]);
        stack<TreeNode*> s;
        s.push(root);
        for(int i=1; i<n; i++)
        {
            auto curr = s.top();
            if(s.empty()==false && p[i]<curr->val){
                curr->left = new TreeNode(p[i]);
                s.push(curr->left);
            }
            else
            {
                TreeNode* temp = s.top();
                while(s.empty()==false && s.top()->val<p[i]){
                    temp = s.top();
                    s.pop();
                }
                temp->right = new TreeNode(p[i]);
                s.push(temp->right);
            }
        }
        return root;
    }
};