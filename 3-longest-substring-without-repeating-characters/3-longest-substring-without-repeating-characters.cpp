class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.length();
        int i=0, j=0;
        int ans = 0;
        while(i<n && j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};