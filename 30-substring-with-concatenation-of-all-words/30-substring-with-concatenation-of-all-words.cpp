class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> word;
        int lenOfWord =0;
        for(auto x: words){
            word[x]++;
            lenOfWord = x.length();
        }
        int stringLen = s.length();
        int noOfWords = words.size();
        int totalLenOfWords = lenOfWord*noOfWords;
        if(totalLenOfWords>stringLen){
            return {};
        }
        
        vector<int> ans;
        
        for(int i=0; i<=(stringLen-totalLenOfWords); i++){
            int j=i;
            unordered_map<string,int> vis;
            bool flag = true;
            while(j<(i+totalLenOfWords)){
                string temp = s.substr(j,lenOfWord);
                if(word.find(temp)==word.end()){
                    flag = false;
                    break;
                }
                if(vis.find(temp)!=vis.end() && vis[temp]==word[temp]){
                    flag = false;
                    break;
                }
                vis[temp]++;
                j = j+lenOfWord;
            }
            if(flag){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};