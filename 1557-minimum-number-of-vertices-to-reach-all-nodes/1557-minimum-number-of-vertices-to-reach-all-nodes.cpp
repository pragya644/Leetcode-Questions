class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        for(auto x: edges)
        {
            visited[x[1]]++;
        }
        vector<int> res;
        for(int i=0; i<n; i++)
            if(visited[i]==0)
                res.push_back(i);
        return res;
    }
};