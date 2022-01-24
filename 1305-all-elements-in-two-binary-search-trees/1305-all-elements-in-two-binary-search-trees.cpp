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
    void solve(TreeNode*root, stack<TreeNode*> &s)
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        solve(root1,s1);
        solve(root2,s2);
        while(!s1.empty() || !s2.empty())
        {
            stack<TreeNode*> &s = s2.empty()?s1:s1.empty()?s2 :
            s1.top()->val < s2.top()->val ? s1 : s2;
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            solve(temp->right,s);
        }
        return res;
    }
};