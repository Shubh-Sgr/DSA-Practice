class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int upperM=matrix.size()-1;
        int upperN=matrix[0].size()-1;
        int lowerM=0;
        int lowerN=0;
        
        while (lowerM<=upperM && lowerN<=upperN){
            for (int col=lowerN; col<=upperN; col++){
                ans.push_back(matrix[lowerM][col]);
            }
            lowerM++;
            
            for (int row=lowerM; row<=upperM; row++){
                ans.push_back(matrix[row][upperN]);
            }
            upperN--;
            
            if (lowerM <= upperM) {
                for (int col=upperN; col>=lowerN; col--){
                    ans.push_back(matrix[upperM][col]);
                }
            }
            upperM--;
            
            if (lowerN <= upperN) {
                for (int row=upperM; row>=lowerM; row--){
                    ans.push_back(matrix[row][lowerN]);
                }
            }
            lowerN++;
            
        }
        
        return ans;
    }
};
