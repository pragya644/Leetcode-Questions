class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string x = strs[0];
        string y = strs[n-1];
        string ans = "";
        for(int i=0; i<x.length(); i++){
            if(x[i]!=y[i])
                return ans;
            ans = ans + x[i];
        }
        return ans;
        
    }
};