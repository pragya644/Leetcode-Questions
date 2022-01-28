class Solution {
public:
    int minSteps(string s, string t) {
        int a[26] = {0};
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(a[i]>0)
                ans += a[i];
        }
        return ans;
    }
};