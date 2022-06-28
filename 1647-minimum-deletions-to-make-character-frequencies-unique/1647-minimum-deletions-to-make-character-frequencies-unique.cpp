class Solution {
public:
    int minDeletions(string s) {
                unordered_map<char,int> no_of_char;
        for(auto x: s)
        {
            no_of_char[x]++;
        }
        unordered_map<int,int> num;
        for(auto x: no_of_char)
        {
            num[x.second]++;
        }
        int ans = 0;
        for(auto x: num)
        {
            int count = x.second;
            while(count>1)
            {
                int val = x.first;
                int temp = val;
                val--;
                while(val>=0)
                {
                    if(val==0)
                    {
                        num[temp]--;
                        count--;
                        ans += (temp-val);
                        break;
                    }
                    if(num[val]==0)
                    {
                        num[val]++;
                        num[temp]--;
                        count--;
                        ans += (temp-val);
                        break;
                    }
                    val--;
                }
            }
        }
        return ans;
    }
};