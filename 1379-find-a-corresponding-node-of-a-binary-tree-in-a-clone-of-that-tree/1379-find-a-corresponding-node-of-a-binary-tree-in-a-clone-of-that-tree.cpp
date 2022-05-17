/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* target) {
        if(o==target)
            return c;
        queue<TreeNode*> q1;
        queue< TreeNode*> q2;
        q1.push(o);
        q2.push(c);
        while(q1.empty()==false)
        {
            auto temp1 = q1.front();
            q1.pop();
            auto temp2 = q2.front();
            q2.pop();
            if(temp1 == target)
                return temp2;
            if(temp1->left!=NULL)
                q1.push(temp1->left);
            if(temp1->right!=NULL)
                q1.push(temp1->right);
            if(temp2->left!=NULL)
                q2.push(temp2->left);
            if(temp2->right!=NULL)
                q2.push(temp2->right);
        }
        return o;
    }
};