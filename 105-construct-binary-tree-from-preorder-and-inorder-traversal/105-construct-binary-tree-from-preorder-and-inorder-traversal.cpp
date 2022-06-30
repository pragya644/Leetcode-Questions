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
    
    //Time Complexity is O(n)
    //Space Complexity is O(n^2)
    
    TreeNode* solve(vector<int> &p, vector<int> &i, int &rootIdx, int l, int r, unordered_map<int,int> &inorder_map)
    {
        if(l>r)
            return NULL;
        int curr = inorder_map[p[rootIdx]];
        rootIdx++;
        TreeNode* root = new TreeNode(i[curr]);
        root->left = solve(p,i,rootIdx,l,curr-1,inorder_map);
        root->right = solve(p,i,rootIdx, curr+1, r,inorder_map);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        unordered_map<int,int> inorder_map;
        for(int i=0; i<inorder.size(); i++)
        {
            inorder_map.insert({inorder[i],i});
        }
        return solve(preorder,inorder,rootIdx,0,inorder.size()-1, inorder_map);
    }
};