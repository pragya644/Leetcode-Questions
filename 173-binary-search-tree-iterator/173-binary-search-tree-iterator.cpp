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
class BSTIterator {
public:
    
    vector<int> v;
    int i= -1;
    
    void help(TreeNode* root)
    {
        if(root==NULL)
            return;
        help(root->left);
        v.push_back(root->val);
        help(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        help(root);
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        if(i+1>=v.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */