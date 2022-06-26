class Solution {
public:
    
    void dfs(int node, unordered_map<int,unordered_set<int>> &in, unordered_map<int,unordered_set<int>> &out,int &ans)
    {
        for(auto x: out[node])
        {
            ans++;
            in[x].erase(node);
            dfs(x,in,out,ans);
        }
        for(auto x: in[node])
        {
            out[x].erase(node);
            dfs(x,in,out,ans);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        unordered_map<int,unordered_set<int>> in, out;
        for(int i=0; i<c.size(); i++)
        {
            out[c[i][0]].insert(c[i][1]);
            in[c[i][1]].insert(c[i][0]);
        }
        int ans = 0;
        dfs(0,in,out,ans);
        return ans;
    }
    
};