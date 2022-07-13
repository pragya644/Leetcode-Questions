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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== NULL)
            return ans;
        queue<TreeNode*> storingNodes;
        storingNodes.push(root);
        while(storingNodes.empty()==false)
        {
            int currSize = storingNodes.size();
            vector<int> oneLevelNodes;
            for(int i=0; i<currSize; i++)
            {
                auto currNode = storingNodes.front();
                storingNodes.pop();
                oneLevelNodes.push_back(currNode->val);
                if(currNode->left!=NULL)
                    storingNodes.push(currNode->left);
                if(currNode->right!=NULL)
                    storingNodes.push(currNode->right);
            }
            ans.push_back(oneLevelNodes);
        }
        return ans;
    }
};