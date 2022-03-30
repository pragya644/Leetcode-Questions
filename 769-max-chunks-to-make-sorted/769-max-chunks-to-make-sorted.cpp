class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int val = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            sum += i;
            val += arr[i];
            if(sum==val)
                count++;
        }
        return count;
    }
};