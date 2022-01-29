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
            for(int j=0; j<m; j++)
            {
                if(v[j]==queries[i])
                {
                    res.push_back(j);
                    int temp = v[j];
                    vector<int>::iterator it;
                    it = v.begin()+j;
                    v.erase(it);
                    v.insert(v.begin(),temp);
                    break;
                }
            }
        }
        return res;
    }
};