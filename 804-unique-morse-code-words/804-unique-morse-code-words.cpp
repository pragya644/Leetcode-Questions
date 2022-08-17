class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        for(auto x: words){
            string t = "";
            for(int i=0; i<x.length(); i++){
                int idx = x[i]-'a';
                t += morse[idx];
            }
            s.insert(t);
        }
        return s.size();
    }
};