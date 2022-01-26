class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(string s: strs)
        {
            string temp = s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto p: m)
            res.push_back(p.second);
        return res;
    }
};