class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans = 0;
        for(int i=24; i>=0; i--)
        {
            if(freq[i]>=freq[i+1])
            {
                int temp = freq[i];
                freq[i] = max(freq[i+1]-1, 0);
                ans += temp-freq[i];
            }
        }
        return ans;
    }
};