class Solution {
public:
    
    bool canDivide(int num, vector<int> &numsDivide)
    {
        for(auto x: numsDivide)
        {
            if(x%num!=0)
                return false;
        }
        return true;
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> numCount;
        for(auto x: nums)
        {
            numCount[x]++;
        }
        int noOfDeletion = 0;
        for(auto it: numCount)
        {
            int num = it.first;
            if(canDivide(num,numsDivide))
            {
                return noOfDeletion;
            }
            noOfDeletion += it.second;
        }
        return -1;
    }
};