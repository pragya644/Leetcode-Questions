class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        int size = words.size();
        for(int i=0; i<size; i++) {
            string curr = words[i];
            for(int j=1; j<curr.length(); j++)
            {
                s.erase(curr.substr(j));
            }
        }
        int ans = 0;
        for(auto word : s) {
            ans += word.size() + 1;
        }
        return ans;
    }
};