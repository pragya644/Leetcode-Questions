class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int temp = 0;
            for(int j=0; j<n; j++)
            {
                if(s[j]=='1')
                {
                    temp += abs(i-j);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};