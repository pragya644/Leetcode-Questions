class Solution {
public:
    
    void fillColor(int i, int j,int prevCol, int col, vector<vector<int>> &image){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=prevCol || image[i][j]==col)
            return;
        prevCol = image[i][j];
        image[i][j] = col;
        fillColor(i+1,j,prevCol,col,image);
        fillColor(i-1,j,prevCol,col,image);
        fillColor(i,j+1,prevCol,col,image);
        fillColor(i,j-1,prevCol,col,image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc,int color){
        int n = image.size();
        int m = image[0].size();
        fillColor(sr,sc,image[sr][sc], color,image);
        return image;
    }
};