class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> ans;
        vector<int> deg(n,0);
        for(int i=0; i<n; i++) {
            for(auto x: adj[i]) {
                deg[x]++;
            }
        }
        for(int i=0; i<n; i++) {
            int node = 0;
            while(node<n) {
                if(deg[node]==0)
                    break;
                node++;
            }
            if(node==n) {
                return { };
            }
            ans.push_back(node);
            deg[node] -= 1;
            for(auto x: adj[node])
                deg[x]--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};