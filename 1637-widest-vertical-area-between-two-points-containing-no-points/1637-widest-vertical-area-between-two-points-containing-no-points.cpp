class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        int n = points.size();
        for(int i=0; i<n; i++)
        {
            v.push_back(points[i][0]);
        }
        sort(v.begin(),v.end());
        int ans = INT_MIN;
        for(int i=1; i<v.size(); i++)
        {
            int x = v[i]-v[i-1];
            ans = max(ans,x);
        }
        return ans;
    }
};