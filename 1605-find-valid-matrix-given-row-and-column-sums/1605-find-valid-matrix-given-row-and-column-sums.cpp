class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        vector<vector<int>> ans;
        int n = row.size();
        int m = col.size();
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=0; j<m; j++)
            {
                int mini = min(row[i],col[j]);
                temp.push_back(mini);
                row[i] = row[i]-mini;
                col[j] = col[j]-mini;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};