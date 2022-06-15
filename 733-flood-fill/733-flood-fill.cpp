class Solution {
public:
    void solve(vector<vector<int>>& img, int i, int j, int ini_c, int c)
    {
        if(i<0 || i>=img.size() || j<0 || j>=img[0].size() || img[i][j]!=ini_c)
            return;
        img[i][j] = c;
        solve(img,i-1,j,ini_c,c);
        solve(img,i+1,j,ini_c,c);
        solve(img,i,j-1,ini_c,c);
        solve(img,i,j+1,ini_c,c);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m = img.size();
        int n = img[0].size();
        if(img[sr][sc]!=color)
            solve(img,sr,sc,img[sr][sc], color);
        return img;
    }
};