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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        s.insert(0);
        while(q.empty()==false)
        {
            TreeNode*temp = q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                temp->left->val = temp->val*2 + 1;
                q.push(temp->left);
                s.insert(temp->val*2+1);
            }
            if(temp->right!=NULL)
            {
                temp->right->val = temp->val*2 + 2;
                q.push(temp->right);
                s.insert(temp->val*2+2);
            }
        }
    }
    
    bool find(int target) {
        return s.find(target)!=s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */