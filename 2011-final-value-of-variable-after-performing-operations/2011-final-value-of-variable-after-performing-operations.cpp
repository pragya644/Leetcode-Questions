class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        int x = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]=="--X" || v[i]=="X--")
                x = x-1;
            if(v[i]=="++X" || v[i]=="X++")
                x = x+1;
        }
        return x;
    }
};