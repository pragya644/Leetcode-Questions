class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& v) 
    {
        auto it = std::find(v.begin(), v.end(), endWord);
        if(it==v.end())
            return 0;
        unordered_set<string> s1;
        for(auto w: v)
            s1.insert(w);
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(q.empty()==false)
        {
            int n = q.size();
            depth++;
            for(int i=0; i<n; i++)
            {
                string curr = q.front();
                q.pop();
                for(int i=0; i<curr.length(); i++)
                {
                    string temp = curr;
                    char x = temp[i];
                    for(char c = 'a'; c<='z'; c++)
                    {
                        if(x==c)
                            continue;
                        temp[i] = c;
                        if(temp==endWord)
                            return depth+1;
                        if(s1.find(temp)!=s1.end())
                        {
                            q.push(temp);
                            s1.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};