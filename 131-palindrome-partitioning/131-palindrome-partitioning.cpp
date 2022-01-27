class Solution {
public:
    void dfs(int i,string s,vector<string>&temp, vector<vector<string>> &res)
    {
        if(i>=s.length())
        {
            res.push_back(temp);
            return;
        }
        for(int j=i; j<s.length(); j++)
        {
            if(ispali(s,i,j))
            {
                temp.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,temp,res);
                temp.pop_back();
            }
        }
        
    }
    bool ispali(string s,int l, int r)
    {
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        dfs(0,s,temp,res);
        return res;
    }
};