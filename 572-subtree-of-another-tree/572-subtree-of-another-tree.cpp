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
    
    bool is_present(TreeNode* root, TreeNode* subRoot)
    {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(subRoot);
        while(!q1.empty() && !q2.empty())
        {
            int n1 = q1.size();
            int n2 = q2.size();
            if(n1!=n2)
                return false;
            auto curr1 = q1.front();
            auto curr2 = q2.front();
            q1.pop();
            q2.pop();
            if(curr1->val!=curr2->val)
                return false;
            if(curr1->left!=NULL && curr2->left!=NULL){ 
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
            else if(curr1->left!=NULL || curr2->left!=NULL)
                return false;
            if(curr1->right!=NULL && curr2->right!=NULL){
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
            else if(curr1->right!=NULL || curr2->right!=NULL)
                return false;
        }
        if(q1.empty()==false || q2.empty()==false)
            return false;
        return true;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            if(curr->val == subRoot->val)
            {
                if(is_present(curr,subRoot))
                    return true;
            }
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        return false;
    }
};