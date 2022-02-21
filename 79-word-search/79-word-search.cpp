class Solution {
public:
    
    bool solve(vector<vector<char>> &board, string word, int i,int j, int idx)
    {
        if(idx==word.length())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;
        if(board[i][j]!=word[idx])
            return false;
        board[i][j] = '*';
        bool check = solve(board,word,i-1,j,idx+1) ||
                     solve(board,word, i+1, j, idx+1)||
                     solve(board,word, i, j-1, idx+1)||
                     solve(board,word, i, j+1, idx+1);
        board[i][j] = word[idx];
        return check;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(solve(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};