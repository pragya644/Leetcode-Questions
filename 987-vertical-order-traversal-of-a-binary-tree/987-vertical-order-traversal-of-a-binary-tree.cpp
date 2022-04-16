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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        // vector<pair<int,vector<int>>> v;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            multiset<pair<int,int>> s;
            int n = q.size();
            for(int i=0; i<n ; i++){
            auto temp = q.front();
            q.pop();
            // m[temp.second].push_back(temp.first->val);
            s.insert({temp.second,temp.first->val});
            if(temp.first->left!=NULL)
                q.push({temp.first->left,temp.second-1});
            if(temp.first->right!=NULL)
                q.push({temp.first->right,temp.second+1});
            }
            for(auto z: s)
                m[z.first].push_back(z.second);
        }
        for(auto x: m)
        {
            vector<int> temp;
            for(auto y: x.second)
                temp.push_back(y);
            ans.push_back(temp);
        }
        return ans;
    }
};