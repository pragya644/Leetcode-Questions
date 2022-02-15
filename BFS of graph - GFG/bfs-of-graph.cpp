// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
         bool visited[V+1];
         for(int i=0; i<=V; i++)
         {
             visited[i] = false;
         }
         queue<int> q;
         q.push(0);
         visited[0] = true;
         while(q.empty()==false)
         {
             int n = q.size();
             for(int i=0; i<n; i++)
             {
                 int u = q.front();
                 res.push_back(u);
                 q.pop();
                 for(auto v: adj[u])
                 {
                     if(visited[v]==false)
                     {
                         q.push(v);
                         visited[v] = true;
                     }
                 }
             }
         }
         return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends