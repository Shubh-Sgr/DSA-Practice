class Solution {
public:
    static bool isSafe(int i, int j, int posArr[], int n){
        bool safe = true;
        for (int k = 0; k<i; k++){
            if (abs(posArr[k]-j) == abs(k-i) || j==posArr[k]){
                safe = false;
                break;
            }
        }
        return safe;
    }

    static void solveUtil(int n, int row, int posArr[], vector<int> temp, vector<vector<string>> &ans){
        if (row == n){
            vector<string> newTemp;
            for (int i=0; i<n; i++){
                string rowStr;
                for (int j=0; j<n; j++){
                    if (temp[i]==j){
                        rowStr+='Q';
                    }else{
                        rowStr+='.';
                    }
                }
                newTemp.push_back(rowStr);
            }
            ans.push_back(newTemp);
            return;
        }

        for (int i=0; i<n; i++){
            if (isSafe(row,i, posArr, n)){
                posArr[row] = i;
                temp.push_back(i);
                solveUtil(n, row+1, posArr, temp, ans);
                posArr[row] = -1;
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp;
        vector<vector<string>> ans;
         int posArr[n];
        for (int i=0; i<n; i++){
            posArr[i] = -1;
        }
        solveUtil(n, 0, posArr, temp, ans);
        return ans;
    }
};
