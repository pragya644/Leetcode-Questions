class Solution {
public:
    
    bool check(string s1, string s2)
    {
        for(int i=0; i<s2.length(); i++)
        {
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int n = products.size();
        for(int i=0; i<searchWord.length(); i++)
        {
            vector<string> temp;
            string prefix = searchWord.substr(0,i+1);
            int k=0;
            while(temp.size()<3 && k<n)
            {
                if(check(products[k], prefix))
                {
                    temp.push_back(products[k]);
                }
                k++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};