class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v;
        vector<int> res;
        for(int i=0; i<m; i++)
        {
            v.push_back(i+1);
        }
        for(int i=0; i<queries.size(); i++)
        {
            int currval = queries[i];
            auto it = find(v.begin(),v.end(),currval);
            int idx = it-v.begin();
            res.push_back(idx);
            v.erase(it);
            v.insert(v.begin(),currval);
        }
        return res;
    }
};