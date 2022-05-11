class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &img, int c0, int c1)
    {
        if(i<0 || j<0 || i>=img.size() || j>=img[0].size() || img[i][j]!=c0)
            return;
        img[i][j] = c1;
        solve(i+1,j,img,c0,c1);
        solve(i,j+1,img,c0,c1);
        solve(i,j-1,img,c0,c1);
        solve(i-1,j,img,c0,c1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int newColor) {
        if(img[sr][sc]!=newColor)
            solve(sr,sc,img,img[sr][sc],newColor);
        return img;
    }
};