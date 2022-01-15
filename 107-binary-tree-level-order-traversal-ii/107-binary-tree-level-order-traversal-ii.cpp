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
    int depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d);
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        res[d-1].push_back(root->val);
        d--;
        while(q.empty()==false)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    res[d-1].push_back(temp->left->val);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    res[d-1].push_back(temp->right->val);
                }
            }
            d--;
        }
        return res;
    }
};