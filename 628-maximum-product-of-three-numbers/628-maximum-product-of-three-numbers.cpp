class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        int n = arr.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i]>max2)
            {
                max3 = max2;
                max2 = arr[i];
            }
            else if(arr[i]>max3)
            {
                max3 = arr[i];
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]<min1)
            {
                min2 = min1;
                min1 = arr[i];
            }
            else if(arr[i]<min2)
                min2 = arr[i];
        }
        int ans1 = min1*min2*max1;
        int ans2 = max1*max2*max3;
        return max(ans1, ans2);
    }
};