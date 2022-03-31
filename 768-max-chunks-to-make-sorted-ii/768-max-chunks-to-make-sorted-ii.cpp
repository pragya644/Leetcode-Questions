class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            int currmax = s.empty()?arr[i] : max(s.top(), arr[i]);
            while(!s.empty() && s.top()>arr[i])
                s.pop();
            s.push(currmax);
        }
        return s.size();
    }
};