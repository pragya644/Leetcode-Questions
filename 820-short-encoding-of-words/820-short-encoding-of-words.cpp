class Solution {
public:
    void insert_suffix(string curr, unordered_set<string> &s) {
        int len = curr.length();
        for(int i=len-1; i>=0; i--) {
            string temp = curr.substr(i, len-i);
            s.insert(temp);
        }
    }
    
     static bool compare( string &s1, string &s2){
        return s1.length() > s2.length();
     }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(),compare);
        unordered_set<string> s;
        int size = words.size();
        int ans = 0;
        for(int i=0; i<size; i++) {
            string curr = words[i];
            if(s.find(curr)!=s.end())
                continue;
            insert_suffix(curr, s);
            ans = ans + curr.length() + 1;
        }
        return ans;
    }
};