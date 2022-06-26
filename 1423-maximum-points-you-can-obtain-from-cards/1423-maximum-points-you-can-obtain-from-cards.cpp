class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        k = n-k;
        int sum = 0;
        int score = 0;
        for(int i=1; i<n; i++){
            cardPoints[i] += cardPoints[i-1];
        }
        sum = cardPoints[n-1];
        if(k==0)
            return sum;
        score = sum - cardPoints[k-1];
        for(int i=k; i<n; i++){
            if(i-k>=0)
            {
                int sub_sum = cardPoints[i]-cardPoints[i-k];
                int temp_score = sum - sub_sum;
                score = max(score,temp_score);
            }
        }
        return score;
    }
};