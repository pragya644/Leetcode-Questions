class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        stack<char> s;
        s.push(num[0]);
        for(int i=1; i<num.length(); i++)
        {
            while(k>0 && s.empty()==false && num[i]<s.top())
            {
                k--;
                s.pop();
            }
            s.push(num[i]);
            if(s.size()==1 && num[i]=='0')
                s.pop();
        }
        while(k>0 && !s.empty())
        {
            s.pop();
            k--;
        }
        while(s.empty()==false)
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        if(res.length()==0)
            return "0";
        return res;
    }
};