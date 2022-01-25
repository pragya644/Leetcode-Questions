class Solution {
public:
    
    bool solve(int x,int y, int x1, int y1,int r)
    {
        int tempx = pow((x-x1),2);
        int tempy = pow((y-y1),2);
        int rr = r*r;
        if(tempx+tempy<=rr)
            return true;
        return false;
    }
    
    int find_lower(vector<vector<int>> &points, int x,int r)
    {
        int l = 0;
        int h = points.size()-1;
        int ans = 0;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int x1 = points[mid][0];
            if(x-x1<=r)
            {
                h = mid-1;
                ans = mid;
            }
            else
                l = mid+1;
        }
        return ans;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int> res;
        sort(points.begin(), points.end());
        for(auto &q : queries)
        {
            int x = q[0];
            int y = q[1];
            int r = q[2];
            int index = find_lower(points,x,r);
            int temp = 0;
            for(int i=index; i<points.size(); i++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                if(x1-x>r)
                    break;
                if(solve(x,y,x1,y1,r))
                    temp++;
            }
            res.push_back(temp);
        }
        return res;
    }
};