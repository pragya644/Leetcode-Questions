class Solution {
public:
    void solve(vector<string> &ans, string &s, int i)
    {
        if(s.length()==i)
        {
            ans.push_back(s);
            return;
        }
        char c = s[i];
        if(islower(s[i]))
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
        solve(ans,s,i+1);
        if(isalpha(c))
        {
            s[i] = c;
            solve(ans,s,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(ans,s,0);
        return ans;
    }
};