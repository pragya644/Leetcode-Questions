class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int n = products.size();
        int l = 0, r = n-1;
        for(int i=0; i<searchWord.length(); i++)
        {
            vector<string> temp;
            while(l<=r &&(products[l].length()<=i || products[l][i]!=searchWord[i]))
            {
                l++;
            }
            while(r>=l &&(products[r].length()<=i || products[r][i]!=searchWord[i]))
            {
                r--;
            }
            int len = r-l+1;
            for(int j=0; j<min(3,len); j++)
            {
                temp.push_back(products[l+j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};