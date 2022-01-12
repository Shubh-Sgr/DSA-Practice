class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result=0;
    for(int i = 0; i < matrix.size(); i++) {
      for(int j = 0; j < matrix[0].size(); j++) {

        // for top most row(i == 0) and left most column j == 0, directly
        // value in the matrix will be added as result.
        if(matrix[i][j] > 0 && i > 0 && j > 0) {
          int Mn = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1]));
          matrix[i][j] = Mn + 1;
        }

        result += matrix[i][j];
      }
    }

    return result;
    }
};
