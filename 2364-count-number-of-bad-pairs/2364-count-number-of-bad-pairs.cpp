class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int goodPair = 0;
        long long int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            long long int diff = nums[i]-i;
            if(m.count(diff)==1){
                goodPair += m[diff];
                m[diff]++;
            }else{
                m[diff] = 1;
            }
        }
        long long int totalPair = (n*(n-1))/2;
        return totalPair-goodPair;
    }
};