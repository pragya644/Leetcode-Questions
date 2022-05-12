class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0;
        for(int i=0; i<edges.size(); i++)
        {
            n = max(n, edges[i][0]);
            n = max(n, edges[i][1]);
        }
        vector<vector<int>> v(n+1);
        for(int i=0; i<edges.size(); i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=1; i<=n; i++)
        {
            if(v[i].size()==n-1)
                return i;
        }
        return -1;
    }
};