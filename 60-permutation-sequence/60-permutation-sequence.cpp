class Solution {
public:
    
    void solve(vector<int> &temp, int n, int &currPermu, int k, vector<int> &ans,bool &flag , vector<bool> &vis)
    {
        if(temp.size()==n){
            currPermu += 1;
            if(currPermu!=k)
                return;
        }
        if(currPermu == k)
        {
            ans = temp;
            flag = true;
            return;
        }
        for(int j=0; j<n; j++)
        {
            if(vis[j+1]==false)
            {
                vis[j+1] = true;
                temp.push_back(j+1);
                solve(temp,n,currPermu,k,ans,flag,vis);
                if(flag==true)
                    return;
                temp.pop_back();
                vis[j+1] = false;
            }
        }
        if(flag==true)
            return;
    }
    
    string getPermutation(int n, int k) {
        int currPermu = 0;
        vector<bool> vis(n+1,false);
        bool flag = false;
        vector<int> temp;
        vector<int> ans;
        solve(temp,n,currPermu,k,ans,flag,vis);
        string s;
        for(auto x: ans)
        {
            s += to_string(x);
        }
        return s;
    }
};