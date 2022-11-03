class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        int time = -1;
        int fresh=0;
        int xDir[] = {1,-1,0,0};
        int yDir[] = {0,0,1,-1};
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        while (!q.empty()){
            int qS = q.size();
            
            while (qS>0){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            int cX,cY;
            for (int i=0; i<4; i++){
                cX=x+xDir[i];
                cY = y+yDir[i];
                if (cX>=0 && cX<n && cY>=0 && cY<m && grid[cX][cY]==1){
                    grid[cX][cY]=2;
                    q.push({cX,cY});
                    fresh--;
                }
            }
                qS--;
            }
            time++;
        }
        if (fresh>0){
            return -1;
        }
        if (time==-1)
            return 0;
        return time;
        
    }
};
