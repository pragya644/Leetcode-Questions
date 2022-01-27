class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty()==false)
                    st.pop();
                else
                    ans++;
            }
        }
        while(st.empty()==false)
        {
            st.pop();
            ans++;
        }
        return ans;
    }
};