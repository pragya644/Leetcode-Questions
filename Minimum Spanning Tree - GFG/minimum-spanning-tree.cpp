// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> weight(V,INT_MAX);
        vector<bool> currentlyInMST(V,false);
        vector<int> parent(V,-1);  // this is for to have the MST by nodes
        weight[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
        pq.push({0,0}); // {weights, nodeNumber}
        while(pq.empty()==false)
        {
            auto curr = pq.top();
            pq.pop();
            int currNode = curr.second;
            currentlyInMST[currNode] = true;
            for(auto x: adj[currNode])
            {
                if(currentlyInMST[x[0]]==false && x[1]<weight[x[0]])
                {
                    weight[x[0]] = x[1];
                    pq.push({x[1], x[0]});
                    parent[x[0]] = currNode;
                }
            }
        }
        int sumOfWeights = 0;
        for(auto x: weight)
        {
            sumOfWeights += x;
        }
        return sumOfWeights;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends