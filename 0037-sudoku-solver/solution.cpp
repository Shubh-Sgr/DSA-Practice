class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>> board,char c)
    {
        int row=3*(i/3);
        int col=3*(j/3);
        for (int l=row; l<row+3; l++)
        {
            for (int m=col; m<col+3; m++)
            {
                if (board[l][m]==c)
                {
                    return false;
                }
            }
        }
        for (int k=0; k<9;  k++)
        {
            if (board[i][k]==c || board[k][j]==c)
            {
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        int n=board.size();
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (board[i][j]=='.')
                {
                    for (char c='1'; c<='9'; c++)
                    {
                        if (isValid(i,j,board,c))
                        {
                            board[i][j] = c;
                            
                        
                        if(solve(board)==true)
                            return true;
                        else
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
