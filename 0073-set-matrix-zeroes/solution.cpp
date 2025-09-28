class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0;
        int c = 0;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 0){
                    if (i == 0){
                        r = 1;
                    }
                    if (j==0){
                        c = 1;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int k=1; k<n; k++){
            for (int l=1; l<m; l++){
                if (matrix[k][0]==0 || matrix[0][l]==0){
                    matrix[k][l] = 0;
                }
            }
        }
        if (r){
            for (int i = 0; i<m; i++){
                matrix[0][i] = 0;
            }
        }
        if (c){
            for (int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
