// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	void dfs(int i, vector<int> transpose[], vector<bool> &vis)
	{
	    vis[i] = true;
	    for(auto x: transpose[i])
	    {
	        if(vis[x]==false)
	        {
	            dfs(x,transpose,vis);
	        }
	    }
	}
	
	void tropologicalSort(int i, vector<int> adj[], vector<bool> &vis, stack<int> &st)
	{
	    vis[i] = true;
	    for(auto x: adj[i])
	    {
	        if(vis[x]==false)
	        {
	            tropologicalSort(x,adj,vis,st);
	        }
	    }
	    st.push(i);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        int noOfSCC = 0;
        
        //step 1: tropological sorting
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++)
        {
            if(vis[i]==false)
            {
                tropologicalSort(i,adj,vis,st);
            }
        }
        
        //step 2: transpose the graph or change the node direction
        vector<int> transpose[V];
        for(int i=0; i<V; i++)
        {
            for(auto x: adj[i])
            {
                transpose[x].push_back(i);
            }
        }
        
        //step 3: doing dfs of transpose matrix on the basic of tropological order
        vector<bool> visited(V,false);
        while(st.empty()==false)
        {
            int curr = st.top();
            st.pop();
            if(visited[curr]==false)
            {
                dfs(curr,transpose,visited);
                noOfSCC++;
            }
        }
        return noOfSCC;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends