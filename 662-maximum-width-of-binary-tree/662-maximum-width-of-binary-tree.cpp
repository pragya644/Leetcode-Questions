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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int>> q;
        int ans = INT_MIN;
        q.push({root,0});
        while(!q.empty())
        {
            int n = q.size();
            int fidx = q.front().second;
            int first,last;
            for(int i=0; i<n; i++)
            {
                auto temp = q.front();
                q.pop();
                int idx = temp.second - fidx; // subtracting the idx of the first element of every row
                if(i==0)
                    first = idx;
                if(i==n-1)
                    last = idx;
                if(temp.first->left!=NULL)
                    q.push({temp.first->left, (long long int) 2*idx+1});
                if(temp.first->right!=NULL)
                    q.push({temp.first->right,(long long int) 2*idx+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};