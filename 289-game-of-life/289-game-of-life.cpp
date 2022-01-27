class Solution {
public:
    int negihbours(int i,int j,int m,int n,vector<vector<int>>& board)
    {
        int count = 0;
        for(int a=i-1; a<i+2; a++)
        {
            for(int b = j-1; b<j+2; b++)
            {
                if((a==i && b==j) || a<0 || b<0 || a>=m || b>=n)
                    continue;
                if(board[a][b]==1 || board[a][b]==3)
                    count++;
            }
        }
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