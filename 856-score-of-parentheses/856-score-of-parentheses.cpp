class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else
            {
                if(st.top()==-1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int res = st.top();
                    st.pop();
                    if(st.top()==-1)
                    {
                        st.pop();
                        st.push(2*res);
                    }
                    else
                    {
                        while(st.empty()==false && st.top()!=-1)
                        {
                            res += st.top();
                            st.pop();
                        }
                        if(st.empty()==false && st.top()==-1){
                            res = res * 2;
                            st.pop();
                        }
                        st.push(res);
                    }
                }
            }
        }
        int ans = 0;
        while(st.empty()==false)
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};