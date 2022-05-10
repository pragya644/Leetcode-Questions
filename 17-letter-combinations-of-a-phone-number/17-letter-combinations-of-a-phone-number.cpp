class Solution {
public:
    const vector<string> num = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        vector<string> res;
        res.push_back("");
        for(auto i: digits)
        {
            vector<string> temp;
            for(auto j: num[i-'0'])
            {
                for(auto k: res)
                {
                    temp.push_back(k+j);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};