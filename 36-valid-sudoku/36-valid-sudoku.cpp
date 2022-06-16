class Solution {
public:
    bool solve(int x, int y, vector<vector<char>> &board)
    {
        unordered_set<char> s;
        for(int i=x; i<3+x; i++)
        {
            for(int j=y; j<3+y; j++)
            {
                if(board[i][j]=='.')
                     continue;
                if(s.find(board[i][j])!=s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
        {
            unordered_set<char> s;
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='.')
                     continue;
                if(s.find(board[i][j])!=s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }
        for(int i=0; i<m; i++)
        {
            unordered_set<char> s;
            for(int j=0; j<n; j++)
            {
                if(board[j][i]=='.')
                     continue;
                if(s.find(board[j][i])!=s.end())
                    return false;
                s.insert(board[j][i]);
            }
        }
        for(int i=0; i<n; i += 3)
        {
            for(int j=0; j<m; j += 3)
            {
                if(solve(i,j, board)==false)
                    return false;
            }
        }
        return true;
    }
};