/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        Node* root = new Node(node->val, {});
        unordered_map<Node*,Node*> m;
        m.insert({node,root});
        queue<Node*> q;
        q.push(node);
        while(q.empty()==false){
            auto curr = q.front();
            q.pop();
            vector<Node*> currNeigh = curr->neighbors;
            for(auto x: currNeigh){
                if(m.find(x)==m.end()){
                    Node* duplicate = new Node(x->val, {});
                    m[x] = duplicate;
                    q.push(x);
                }
                m[curr]->neighbors.push_back(m[x]);
            }
        }
        return root;
    }
};