class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> letter(26,0);
        for(int i=0; i<s.length(); i++)
            letter[s[i]-'a'] = i;
        vector<int> res;
        int maxi = INT_MIN;
        int last = 0;
        for(int i=0; i<s.length(); i++)
        {
            maxi = max(maxi,letter[s[i]-'a']);
            if(i==maxi){
                int x = maxi-last+1;
                res.push_back(x);
                 last = maxi+1;
            }
        }
        return res;
    }
};