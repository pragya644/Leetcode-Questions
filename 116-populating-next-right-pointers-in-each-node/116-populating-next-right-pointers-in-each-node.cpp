/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int n = q.size();
            for(int i=0; i<n-1; i++)
            {
                auto curr = q.front();
                q.pop();
                auto side = q.front();
                curr->next = side;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            auto last = q.front();
            q.pop();
            last->next = NULL;
            if(last->left!=NULL)
                q.push(last->left);
            if(last->right!=NULL)
                q.push(last->right);
        }
        return root;
    }
};