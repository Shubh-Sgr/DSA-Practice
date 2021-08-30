class Solution {
public:
    
    bool isSafe(int i,int j,int col[],int n)
    {
        for (int k=0; k<i; k++)
        {
            if (j==col[k] || abs(k-i)==abs(j-col[k]))
                return false;
        }
        return true;
    }
    
    void solveNQueensUtil(vector<int> temp,vector<vector<string>> &ans,int n,int col[],int i)
    {
        if (i==n)
        {
            string s;
            vector<string> Ans;
            for (int j=0; j<n; j++)
            {
                s="";
                for (int k=0; k<n; k++)
                {
                    if (k==temp[j])
                    {
                        s+="Q";
                    }
                    else
                    {
                        s+=".";
                    }
                }
                Ans.push_back(s);
            }
            ans.push_back(Ans);
            return;
        }
        for (int j=0; j<n; j++)
        {
            if (isSafe(i,j,col,n))
            {
                col[i]=j;
                temp.push_back(j);
                solveNQueensUtil(temp,ans,n,col,i+1);
                temp.pop_back();
                col[i]=-1;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<int> temp;
       vector<vector<string>> ans;
        int col[n];
        for (int i=0; i<n; i++)
        {
            col[i]=-1;
        }
        solveNQueensUtil(temp,ans,n,col,0);
        return ans;
    }
};
