class WordFilter {
public:
    unordered_map<string,int>  m;
    
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            string s = words[i];
            int l = s.length();
            for(int j=1; j<=l; j++)
            {
                string pre = s.substr(0,j);
                for(int k=0; k<l; k++)
                {
                    string suf = s.substr(k,l);
                    m[pre+"."+suf] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = prefix + "."+ suffix;
        if(m.find(temp)!=m.end())
            return m[temp];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */