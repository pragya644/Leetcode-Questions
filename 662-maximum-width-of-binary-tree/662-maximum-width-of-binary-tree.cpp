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
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            int n = q.size();
            int first, last;
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                int curr_val = curr.second;
                q.pop();
                if(i==0)
                {
                    first = curr.second;
                }
                if(i==n-1)
                {
                    last = curr.second;
                }
                if(curr.first->left!=NULL){
                    q.push({curr.first->left,(long long int)curr_val*2+1});
                }
                if(curr.first->right!=NULL){
                    q.push({curr.first->right,(long long int)curr_val*2+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};