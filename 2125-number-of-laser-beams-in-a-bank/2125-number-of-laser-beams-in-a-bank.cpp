class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(count1==0)
            {
                for(int j=0; j<bank[i].length(); j++)
                {
                    if(bank[i][j]=='1')
                        count1++;
                }
            }
            else if(count2==0)
            {
                for(int j=0; j<bank[i].length(); j++)
                {
                    if(bank[i][j]=='1')
                        count2++;
                } 
            }
            if(count1!=0 && count2!=0)
            {
                ans += count1*count2;
                count1 = count2;
                count2 = 0;
            }
        }
        return ans;
    }
};