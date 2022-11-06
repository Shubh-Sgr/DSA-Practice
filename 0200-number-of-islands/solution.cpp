class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &vis){
        if (grid[i][j]=='0'){
            return;
        }
        vis[i][j]=true;
        if (i-1>=0 && !vis[i-1][j]){
            dfs(i-1,j,grid,vis);
        }
        if (i+1<grid.size() && !vis[i+1][j]){
            dfs(i+1,j,grid,vis);
        }
        if (j-1>=0 && !vis[i][j-1]){
            dfs(i,j-1,grid,vis);
        }
        if (j+1<grid[0].size() && !vis[i][j+1]){
            dfs(i,j+1,grid,vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int count=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};
