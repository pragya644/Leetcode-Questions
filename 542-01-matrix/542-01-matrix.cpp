class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]!=0) {
                    mat[i][j] = -1;
                }
                else {
                    q.push({i,j});
                }
            }
        }
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int i=0; i<4; i++)
            {
                int row = x+dir[i].first;
                int col = y+dir[i].second;
                if(row>=0 && row<n && col>=0 && col<m && mat[row][col]==-1)
                {
                    mat[row][col] = 1+mat[x][y];
                    q.push({row,col});
                }
            }
        }
        return mat;
        
    }
};



//why not ths??


        // int n = mat.size();
        // int m = mat[0].size();
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(mat[i][j]==1)
        //         {
        //             int temp = INT_MAX;
        //             if(i>=0 && temp>mat[i-1][j]){
        //                 temp = mat[i-1][j];
        //             }
        //             if(i<n && temp>mat[i+1][j])
        //                 temp = mat[i+1][j];
        //             if(j>=0 && temp>mat[i][j-1])
        //                 temp = mat[i][j-1];
        //             if(j<m && temp>mat[i][j+1])
        //                 temp = mat[i][j+1];
        //             mat[i][j] = temp + 1;
        //         }
        //     }
        // }
        // return mat;