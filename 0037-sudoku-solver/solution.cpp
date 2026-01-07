class Solution {
public:
    bool isSafe(int i, int j, char num, vector<vector<char>>& board){
        int rowNum = 3*(i/3);
        int colNum = 3*(j/3);
        int rowSize = rowNum+3;
        int colSize = colNum+3;
        for (int r=rowNum; r<rowSize; r++){
            for (int s=colNum; s<colSize; s++){
                if (board[r][s]==num){
                    return false;
                }
            }
        }
        for (int k=0; k<9; k++){
            if (board[k][j]==num || board[i][k]==num){
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j]=='.'){
                    for (int k=1; k<=9; k++){
                        char c = '0' + k;
                        if (isSafe(i,j,c,board)){
                            board[i][j] = c;
                            if (solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }           
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
