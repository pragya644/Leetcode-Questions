class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int noOfElem = nums.size();
        unordered_map<int,int> freqOfNo; 
        for(auto x: nums){
            freqOfNo[x]++;
        }
        
        unordered_map<int,int> noReqsubseq;
        
        for(int i=0; i<noOfElem; i++){
            if(freqOfNo[nums[i]]==0){
                continue;
            }
            if(noReqsubseq[nums[i]]>0){
                noReqsubseq[nums[i]]--;
                freqOfNo[nums[i]]--;
                noReqsubseq[nums[i]+1]++;
                
            }else if(freqOfNo[nums[i]]>0 && freqOfNo[nums[i]+1]>0 && freqOfNo[nums[i]+2]>0){
                    freqOfNo[nums[i]]--;
                    freqOfNo[nums[i]+1]--;
                    freqOfNo[nums[i]+2]--;
                    
                    noReqsubseq[nums[i]+3]++;
            }else{
                return false;
            }
        }
        return true;

    }
};