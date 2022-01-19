class Solution {
public:
    void pare(vector<string> &ans, string s, int op, int cl)
    {
        if(op==0 && cl==0)
            ans.push_back(s);
        if(op>0)
           pare(ans, s+'(',op-1, cl);
        if(cl>op)
             pare(ans, s+')',op, cl-1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        pare(ans,"",n,n);
        return ans;
    }
};