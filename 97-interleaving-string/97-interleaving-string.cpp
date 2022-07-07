class Solution {
public:
   
    int memo[101][101][201];
    
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3)
    {
        if(i>=s1.length() && j>=s2.length() && k>=s3.length())
            return true;
        if(memo[i][j][k]!=-1)
            return memo[i][j][k];
        return memo[i][j][k]  =  (s1[i]==s3[k] && solve(i+1,j,k+1,s1,s2,s3)) || (s2[j]==s3[k] && solve(i,j+1,k+1,s1,s2,s3));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int m = s3.length();
        memset(memo,-1,sizeof(memo));
        if(n1+n2!=m)
            return false;
        return solve(0,0,0,s1,s2,s3);
    }
};