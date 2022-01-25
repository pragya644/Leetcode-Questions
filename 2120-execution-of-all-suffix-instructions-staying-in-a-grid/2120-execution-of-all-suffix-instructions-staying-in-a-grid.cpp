class Solution {
public:
    bool isvalid(int n, int x,int y)
    {
        if((x<n && x>=0) && (y<n && y>=0))
            return true;
        return false;
    }
    void solve(char c, int &x, int &y)
    {
        if(c=='L')
            y = y-1;
        else if(c=='R')
            y = y+1;
        else if(c=='D')
            x = x+1;
        else if(c=='U')
            x = x-1;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int m = s.length();
        for(int i=0; i<m; i++)
        {
            int x = startPos[0];
            int y = startPos[1];
            int temp = 0;
            for(int j=i; j<m; j++)
            {
                solve(s[j],x,y);
                if(isvalid(n,x,y))
                    temp++;
                else
                    break;
            }
            res.push_back(temp);
        }
        return res;
    }
};