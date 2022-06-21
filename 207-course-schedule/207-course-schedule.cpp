class Solution {
public:
    
    //time complexity is O(n+e), e is no of prerequisite or pre.size();
    //space compexity is 
    
    //tropological sorting
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> deg(n,0);
        for(int i=0; i<n; i++) {
            for(auto x: adj[i]) {
                deg[x]++;
            }
        }
        for(int i=0; i<n; i++) {
            int node = 0;
            while(node<n)
            {
                if(deg[node]==0)
                    break;
                node++;
            }
            if(node==n) {
                return false;
            }
            deg[node]--;
            for(auto x: adj[node]) {
                deg[x]--;
            }
        }
        return true;
    }
};