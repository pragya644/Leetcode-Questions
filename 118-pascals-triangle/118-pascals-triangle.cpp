class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++)
        {
            int currpos = i;
            vector<int> temp;
            temp.push_back(1);
            currpos--;
            if(currpos>0)
            {
                for(int k=1; k<=currpos-1; k++)
                {
                    int val = ans[i-2][k]+ans[i-2][k-1];
                    temp.push_back(val);
                }
                temp.push_back(1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};