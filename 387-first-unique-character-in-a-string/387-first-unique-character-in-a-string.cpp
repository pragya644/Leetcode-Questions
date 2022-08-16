class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        int ans = INT_MAX;
        for(auto x: m){
            pair<int,int> temp = x.second;
            if(temp.first == 1){
                ans = min(ans, temp.second);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};