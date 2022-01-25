class SubrectangleQueries {
public:
    vector<vector<int>> temp;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        temp = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        int m = temp[0].size();
        while(row1<=row2 && col1<=col2)
        {
            for(int i=col1; i<=col2; i++)
            {
                temp[row1][i] = newValue;
            }
            row1++;
        }
    }
    
    int getValue(int row, int col) {
        int x = temp[row][col];
        return x;
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */