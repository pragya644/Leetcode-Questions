class Solution {
public:
    
    bool canMakeSquare(int i,int currSum,int target,int side,vector<bool> &vis,vector<int> &m)
    {
        if(side==1)
            return true;
        if(currSum == target)
            return canMakeSquare(0,0,target,side-1,vis,m);
        for(int j=i; j<m.size(); j++)
        {
            if(vis[j]==true || m[j]+currSum>target)
                continue;
            vis[j] = true;
            if(canMakeSquare(j+1,currSum+m[j], target,side,vis,m))
                return true;
            vis[j] = false;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int totalSum = 0;
        for(auto x: matchsticks)
        {
            totalSum += x;
        }
        if(n<4 || totalSum%4!=0)
            return false;
        int target = totalSum/4;
        int side = 4;
        vector<bool> vis(n,false);
        return canMakeSquare(0,0,target,side,vis,matchsticks);
    }
};