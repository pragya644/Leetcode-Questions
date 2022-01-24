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
    void solve(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    
    void merge(vector<int> v1, vector<int> v2, vector<int> &ans)
    {
        int i=0,j=0;
        int n = v1.size();
        int m = v2.size();
        while(i<n && j<m)
        {
            if(v1[i]<v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            else if(v2[j]<v1[i])
            {
                ans.push_back(v2[j]);
                j++;
            }
            else
            {
                ans.push_back(v1[i]);
                ans.push_back(v2[j]);
                i++;
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(v1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        solve(root1,v1);
        solve(root2,v2);
        vector<int> ans;
        merge(v1,v2,ans);
        return ans;
    }
};