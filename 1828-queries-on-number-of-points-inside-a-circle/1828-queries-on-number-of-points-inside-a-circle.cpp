class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int> res;
        for(auto &q: queries)
        {
            int temp = 0;
            int r = q[2]*q[2];
            for(auto &p: points)
            {
                int x = pow((p[0]-q[0]),2);
                int y = pow((p[1]-q[1]),2);
                if(x+y<=r)
                    temp++;
            }
            res.push_back(temp);
        }
        return res;
    }
};