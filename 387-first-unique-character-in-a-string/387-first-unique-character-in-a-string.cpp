class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        int ans = INT_MAX;
        for(int i=0; i<s.length(); i++)
        {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for(const auto& [c,s]:m)
        {
            if(s.first==1)
                ans = min(ans,s.second);
        }
        return ans==INT_MAX ?-1 : ans;
    }
};