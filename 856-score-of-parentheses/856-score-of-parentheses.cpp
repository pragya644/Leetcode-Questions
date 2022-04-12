class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(auto c: s)
        {
            if(c=='(')
            {
                st.push(ans);
                ans = 0;
            }
            else
            {
                ans = st.top() + max(2*ans, 1);
                st.pop();
            }
        }
        return ans;
    }
};