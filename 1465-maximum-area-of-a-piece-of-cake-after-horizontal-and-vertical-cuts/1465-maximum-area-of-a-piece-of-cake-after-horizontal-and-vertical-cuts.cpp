class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        const int mod = 1e9 + 7;
        sort(ho.begin(), ho.end());
        sort(ve.begin(), ve.end());
        ho.push_back(h);
        ve.push_back(w);
        int max_h = ho[0];
        for(int i=1; i<ho.size(); i++)
            max_h = max(max_h, ho[i]-ho[i-1]);
        int max_v = ve[0];
        for(int i=1; i<ve.size(); i++)
            max_v = max(max_v, ve[i]-ve[i-1]);
        return  ((long)max_v*max_h)%mod;
    }
};