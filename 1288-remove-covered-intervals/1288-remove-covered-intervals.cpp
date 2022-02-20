class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& i) {
        sort(i.begin(), i.end(),comp);
        int start = i[0][0];
        int end = i[0][1];
        int ans = 1;
        for(int j=1; j<i.size(); j++)
        {
            if(i[j][1]>end)
            {
                start = i[j][0];
                end = i[j][1];
                ans++;
            }
        }
        return ans;
    }
};