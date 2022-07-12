class Solution {
public:
    

    void solve(int i, int j, vector<vector<int>> &image, int prev,int col)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=prev)
            return ;
        int temp = image[i][j];
        image[i][j] = col;
        solve(i+1,j,image,temp,col);
        solve(i,j+1,image,temp,col);
        solve(i,j-1,image,temp,col);
        solve(i-1,j,image,temp,col);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc]==color)
            return image;
        solve(sr,sc,image,image[sr][sc],color);
        return image;
    }
};