class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int,int>> s;
        for(int i=0; i<n; i++)
        {
            pair<int,int> temp = make_pair(arr[i], arr[i]);
            while(!s.empty() && s.top().first>temp.second)
            {
                auto x = s.top();
                s.pop();
                temp.second = min(x.second, temp.second);
                temp.first = max(x.first, temp.first);
            }
            s.push(temp);
        }
        return s.size();
    }
};