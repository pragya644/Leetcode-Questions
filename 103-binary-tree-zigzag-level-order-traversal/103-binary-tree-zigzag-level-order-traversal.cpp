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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(q.empty()==false)
        {
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            if(!flag)
            {
                reverse(temp.begin(), temp.end());
                flag = true;
            }
            else
                flag = false;
            ans.push_back(temp);
        }
        return ans;
    }
};