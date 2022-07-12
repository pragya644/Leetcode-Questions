class Solution {
public:
    
    bool isSquare(int i, int target,vector<int> &m,int s1,int s2, int s3, int s4)
    {
        if(s1>target || s2>target || s3>target || s4>target)
            return false;
        if(i==m.size())
            return true;
        bool r1 = isSquare(i+1,target,m,s1+m[i],s2,s3,s4);
        bool r2 = isSquare(i+1,target,m,s1,s2+m[i],s3,s4);
        bool r3 = isSquare(i+1,target,m,s1,s2,s3+m[i],s4);
        bool r4 = isSquare(i+1,target,m,s1,s2,s3,s4+m[i]);
        return r1||r2||r3||r4;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int totalSum = 0;
        for(auto x: matchsticks)
            totalSum += x;
        if(n<4 || totalSum%4!=0)
            return false;
        int target = totalSum/4;
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        int side1 =0, side2 = 0, side3 = 0, side4 = 0;
        return isSquare(0,target,matchsticks,side1, side2, side3,side4);
    }
};