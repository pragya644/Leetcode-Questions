class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int count = 0;
        for(string s: bank)
        {
            for(int i=0; i<s.length(); i++)
                if(s[i]=='1')
                    count++;
            if(count)
            {
                ans += count*prev;
                prev = count;
                count = 0;
            }
        }
        return ans;
    }
};