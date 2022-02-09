class Solution {
public:
    bool palindrome(string s,int l,int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void solve(string s, int i, vector<string> &temp, vector<vector<string>> &res)
    {
        if(i==s.length())
        {
            res.push_back(temp);
            return;
        }
        for(int j=i; j<s.length(); j++)
        {
            if(palindrome(s,i,j))
            {
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1,temp,res);
                temp.pop_back();
            }
        }
    } 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(s,0,temp,res);
        return res;
    }
};