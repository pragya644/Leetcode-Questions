class Solution {
public:
    int negihbours(int i,int j,int m,int n,vector<vector<int>>& board)
    {
        int count = 0 ;
        if(i>0)
            if(board[i-1][j]==1 || board[i-1][j]==3 ) 
                count++;
        if(j>0)
            if(board[i][j-1]==1 || board[i][j-1]==3) 
                count++;
        if(i<m-1)
            if(board[i+1][j]==1 || board[i+1][j]==3) 
                count++;
        if(j<n-1)
            if(board[i][j+1]==1 || board[i][j+1]==3) 
                count++;
        if(i>0 && j>0)
            if(board[i-1][j-1]==1 || board[i-1][j-1]==3) 
                count++;
        if(i<m-1 && j<n-1)
            if(board[i+1][j+1]==1 || board[i+1][j+1]==3) 
                count++;
        if(i>0 && j<n-1)
            if(board[i-1][j+1]==1 || board[i-1][j+1]==3) 
                count++;
        if(i<m-1 && j>0)
            if(board[i+1][j-1]==1 || board[i+1][j-1]==3) 
                count++;
        return count;
    }
    
    void modify(vector<vector<int>> &board,int m,int n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==2)
                    board[i][j] = 1;
                else if(board[i][j]==3)
                    board[i][j] = 0;
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m= board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int count = negihbours(i,j,m,n,board);
                if(board[i][j]==1)
                {
                    if(count<2 || count>3)
                        board[i][j] = 3;
                }
                else if(board[i][j]==0)
                {
                    if(count==3)
                        board[i][j] = 2;
                }
            }
        }
        modify(board,m,n);
    }
};