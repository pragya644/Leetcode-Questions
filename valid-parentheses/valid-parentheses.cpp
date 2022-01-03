class Solution {
public:
    bool issafe(char x, char y)
    {
        if(x=='(' && y==')')
            return true;
        if(x=='{' && y=='}')
            return true;
        if(x=='[' && y==']')
            return true;
        return false;
    }
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(!st.empty())
            {
                if(issafe(st.top(),s[i]))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(st.empty()==true)
           return true;
        return false;
    }
};