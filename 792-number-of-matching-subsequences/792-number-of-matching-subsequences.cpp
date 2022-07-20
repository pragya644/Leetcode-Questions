class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int noOfWords = words.size();
        int stringLength = s.length();
        
        unordered_map<char,vector<int>> storingChar;
        for(int i=0; i<stringLength; i++){
            storingChar[s[i]].push_back(i);
        }
        
        
        int noOfSubsequenece = 0;
        for(auto x: words){
            int len = x.length();
            int i = 0;
            int lastIdx = -1;
            while(i<len){
                bool flag = false;
                if(storingChar.find(x[i])!=storingChar.end()){
                    auto it = upper_bound(storingChar[x[i]].begin(), storingChar[x[i]].end(),lastIdx);
                    if(it == storingChar[x[i]].end()){
                        break;
                    }else{
                        lastIdx = *it;
                    }
                    
                }else{
                    break;
                }
                i++;
            }
            if(i==len)
                noOfSubsequenece++;
        }
        return noOfSubsequenece;
    }   
};