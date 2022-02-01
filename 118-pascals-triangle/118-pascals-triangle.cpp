class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=0; j<=i; j++)
            {
                if(j==0 || j==i)
                    temp.push_back(1);
                else
                {
                    int num = res[i-1][j-1] + res[i-1][j];
                    temp.push_back(num);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};