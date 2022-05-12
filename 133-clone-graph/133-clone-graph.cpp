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
        Node* res = new Node(node->val,{});
        unordered_map<Node*, Node*> m;
        m[node] = res;
        queue<Node*> q;
        q.push(node);
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            for(auto n: curr->neighbors)
            {
                if(m.find(n)==m.end())
                {
                    m[n] = new Node(n->val, {});
                    q.push(n);
                }
                m[curr]->neighbors.push_back(m[n]);
            }
        }
        return res;
    }
};