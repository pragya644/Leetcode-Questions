class Solution {
public:
    int dominantIndex(vector<int>& arr) {
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i=0; i<n; i++)
            maxi = max(maxi, arr[i]);
        for(int i=0; i<n; i++)
        {
            if(maxi!=arr[i])
            {
                if(maxi<2*arr[i])
                    return -1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)
            if(arr[i]==maxi)
            {
                ans = i;
                break;
            }
        return ans;
    }
};