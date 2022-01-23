class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<int> ans;
        for (int i=0; i<col; i++)
        {
            ans.push_back(-1);
        }
        
        if (row==1 && col==1)
        {
            return ans;
        }
        
        for (int i=0; i<col; i++)
        {
            int r=0,c=i;
            
            while (r>=0 && r<row && c>=0 && c<col)
            {
                if (grid[r][c]==1)
                {
                    if (c+1<col && grid[r][c+1]==-1)
                    {
                        break;
                    }
                    c++;
                }
                else
                {
                    if (c-1>=0 && grid[r][c-1]==1)
                    {
                        break;
                    }
                    c--;
                }
                r++;
            }
            if (r==row)
            {
                ans[i]=c;
            }
        }
        return ans;
    }
};
