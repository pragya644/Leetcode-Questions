class Solution {
public:
    int dominantIndex(vector<int>& arr) {
        if(arr.size()==1)
            return 0;
        int max1 = INT_MIN, max2 = INT_MIN;
        int idx = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>max1)
            {
                max2 = max1;
                max1 = arr[i];
                idx = i;
            }
            else if(arr[i]>max2)
                max2 = arr[i];
        }
        return max1>=max2*2 ? idx : -1;
    }
};