class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        if(arr[start]==0)
            return true;
        queue<int> q;
        q.push(start);
        while(q.empty()==false)
        {
            int l = q.size();
            for(int i=0; i<l; i++)
            {
                int curr = q.front();
                vis[curr] = true;
                q.pop();
                if(arr[curr]==0)
                    return true;
                if(curr+arr[curr]<n && vis[curr+arr[curr]]==false)
                    q.push(curr+arr[curr]);
                if(curr-arr[curr]>=0 && vis[curr-arr[curr]]==false)
                    q.push(curr-arr[curr]);
            }
        }
        return false;
    }
};