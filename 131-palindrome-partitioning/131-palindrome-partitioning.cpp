class Solution {
    
public:
    
    //time complexity is O(n*2^n)

    
    vector<vector<bool>> dp{17,vector<bool> (17,false)};
    
    void solve(int i,string s,vector<string> &temp, vector<vector<string>>&ans)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<s.size(); j++)
        {
            if(s[i]==s[j] && (j-i<2 || dp[i+1][j-1]))
            {
                dp[i][j] = true;
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};