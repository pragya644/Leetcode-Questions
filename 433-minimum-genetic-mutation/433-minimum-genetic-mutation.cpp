class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> word(bank.begin(), bank.end());
        if(word.find(end)==word.end())
            return -1;
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(q.empty()==false)
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                string curr = q.front();
                q.pop();
                if(curr==end)
                    return ans;
                word.erase(curr);
                for(int i=0; i<8; i++)
                {
                    string temp = curr;
                    temp[i] = 'A';
                    if(word.find(temp)!=word.end())
                        q.push(temp);
                    temp[i] = 'C';
                    if(word.find(temp)!=word.end())
                        q.push(temp);
                    temp[i] = 'G';
                    if(word.find(temp)!=word.end())
                        q.push(temp);
                    temp[i] = 'T';
                    if(word.find(temp)!=word.end())
                        q.push(temp);
                }
            }
            ans++;
        }
        return -1;
    }
};