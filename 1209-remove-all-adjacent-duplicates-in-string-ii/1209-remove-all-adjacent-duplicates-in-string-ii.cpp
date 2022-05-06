class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<int> v(n,1);
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++)
        {
            if(st.empty()==false)
                if(s[st.top()]==s[i])
                    v[i] = v[st.top()]+1;
            st.push(i);
            if(v[st.top()]==k)
            {
                for(int i=0; i<k; i++)
                    st.pop();
            }
        }
        string ans = "";
        while(st.empty()==false)
        {
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};