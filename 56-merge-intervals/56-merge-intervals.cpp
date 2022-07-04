class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            int lastidx = ans.size()-1;
            if(intervals[i][0]<= ans[lastidx][1])
            {
               ans[lastidx][0] = min(ans[lastidx][0], intervals[i][0]);
               ans[lastidx][1] = max(ans[lastidx][1], intervals[i][1]);
            }
            else
            {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};