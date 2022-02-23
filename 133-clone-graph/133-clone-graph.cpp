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
        if(!node)
            return NULL;
        unordered_map<Node*, Node*> m;
        
        Node* clone = new Node(node->val, {});
        m[node] = clone;
        queue<Node*> q;
        q.push(node);
        while(q.empty()==false)
        {
            Node*curr = q.front();
            q.pop();
            for(Node* neigh: curr->neighbors)
            {
                if(m.find(neigh)==m.end())
                {
                    m[neigh] = new Node(neigh->val, {});
                    q.push(neigh);
                }
                m[curr]->neighbors.push_back(m[neigh]);
            }
        }
        return clone;
    }
};