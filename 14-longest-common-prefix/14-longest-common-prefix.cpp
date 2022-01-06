class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string num = strs[0];
        int l = num.length();
        for(string x: strs)
        {
            if(x.length()<l)
                l = x.length();
        }
        int index = 0;
        string res = "";
        for(char c: num)
        {
            for(int i=1; i<strs.size(); i++)
            {
                if(strs[i][index]!=c || index>l)
                    return res;
            }
            res = res + c;
            index++;
        }
        return res;
    }
};