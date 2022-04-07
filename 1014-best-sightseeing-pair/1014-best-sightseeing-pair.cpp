class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxisofar = values[0]+0;
        int res = 0;
        for(int i=1; i<n; i++)
        {
            maxisofar = max(maxisofar, values[i-1]+i-1);
            res = max(res, values[i]-i+maxisofar);
        }
        return res;
    }
};