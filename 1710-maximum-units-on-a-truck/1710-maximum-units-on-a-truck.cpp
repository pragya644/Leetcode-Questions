class Solution {
public:
    
    static bool compare (vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int n = boxTypes.size();
        int i=0;
        int maxUnits = 0;
        while(truckSize>=0 && i<n){
            if(boxTypes[i][0]<=truckSize)
            {
                int currUnit = boxTypes[i][0]*boxTypes[i][1];
                maxUnits += currUnit;
                truckSize -= boxTypes[i][0];
                i++;
            }
            else
            {
                int currUnit = boxTypes[i][1]*truckSize;
                maxUnits += currUnit;
                truckSize = 0;
                return maxUnits;
            }
        }
        return maxUnits;
    }
};