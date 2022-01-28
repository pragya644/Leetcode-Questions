class Solution {
public:
    string s;
    map<int,int> vis;
    void solve(string tiles,set<string> &res)
    {
        for(int i=0; i<tiles.length(); i++)
        {
            if(vis[i]==0)
            {
                s.push_back(tiles[i]);
                res.insert(s);
                vis[i] = 1;
                solve(tiles,res);
                s.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        set<string> res;
        int n = tiles.length();
        solve(tiles,res);
        return res.size();
    }
};