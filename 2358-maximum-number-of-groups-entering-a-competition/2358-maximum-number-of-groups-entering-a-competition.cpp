class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int k=1;
        int total = 1;
        while((total)<=n){
            k++;
            total += k;
        }
        return k-1;
    }
};