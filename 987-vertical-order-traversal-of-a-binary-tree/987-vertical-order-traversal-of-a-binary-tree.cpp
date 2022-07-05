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
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            unordered_map<int,multiset<int>> temp;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                q.pop();
                temp[curr.second].insert(curr.first->val);
                if(curr.first->left!=NULL)
                    q.push({curr.first->left,curr.second-1});
                if(curr.first->right!=NULL)
                    q.push({curr.first->right, curr.second+1});
            }
            for(auto x: temp)
            {
                for(auto y: x.second)
                    m[x.first].push_back(y);
            }
        }
        vector<vector<int>> ans;
        for(auto x: m)
        {
            vector<int> v;
            for(auto y: x.second)
                v.push_back(y);
            ans.push_back(v);
        }
        return ans;
    }
};