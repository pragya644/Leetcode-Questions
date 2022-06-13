class Solution {
public:
    bool check(char x, char y)
    {
        if(y=='(' && x==')')
            return true;
        if(y=='[' && x==']')
            return true;
        if(y=='{' && x=='}')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(auto x : s)
        {
            if(x=='(' || x=='[' || x=='{')
                st.push(x);
            else if(!st.empty())
            {
                if(check(x,st.top()))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};