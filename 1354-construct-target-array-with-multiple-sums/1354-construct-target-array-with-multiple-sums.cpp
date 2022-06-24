class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq(target.begin(), target.end());
        long long int sum = 0;
        for(int i=0; i<n; i++)
            sum += target[i];
        while(pq.top()!=1){
            sum -= pq.top();
            if(sum>pq.top() || sum==0)
                return false;
            int old = pq.top()%sum;
            if(old==0 && sum!=1)
                return false;
            pq.pop();
            sum += old;
            pq.push(old);
        }
        return true;
    }
};