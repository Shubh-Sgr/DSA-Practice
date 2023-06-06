class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0){
            return false;
        }
        int n = matrix[0].size();
        int xCurr = 0;
        int yCurr = n-1;
        bool flag= false;

        while (xCurr <m && yCurr>=0){
            if (matrix[xCurr][yCurr]>target){
                yCurr--;
            }
            else if (matrix[xCurr][yCurr]<target){
                xCurr++;
            }
            else if (matrix[xCurr][yCurr]==target){
                xCurr++;
                flag=true;
                break;
            }
        }
        return flag;
    }
};
