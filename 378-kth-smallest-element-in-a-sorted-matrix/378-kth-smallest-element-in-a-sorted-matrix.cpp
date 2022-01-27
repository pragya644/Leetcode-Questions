class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int check = 0;
        int n = matrix.size();
        int i = 0;
        while(i<n)
        {
            int j = 0;
            while(j<n)
            {
                pq.push(matrix[i][j]);
                j++;
                if(pq.size()>k)
                    pq.pop();
            }
            i++;
        }
        return pq.top();
    }
};