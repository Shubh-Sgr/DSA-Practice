class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=0,c=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (matrix[i][j]==0)
                {
                    if (i==0) r=1;
                     if (j==0) c=1;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(c){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(r){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};
