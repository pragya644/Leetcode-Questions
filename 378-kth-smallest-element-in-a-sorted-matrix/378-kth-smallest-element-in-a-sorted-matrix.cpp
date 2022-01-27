class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = matrix.size();
        int i = 0;
        k = (n*n)-k+1;
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