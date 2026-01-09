class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int time = -1;
       int freshOranges = 0;
       int x[4] = {-1,1,0,0};
       int y[4] = {0,0,-1,1};

       int m = grid.size();
       int n = grid[0].size();

       for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j]==1){
                freshOranges++;
            }else if (grid[i][j]==2){
                q.push({i,j});
            }
        }
       }

       while (!q.empty()){
            int size = q.size();

            while (size>0){
                pair<int,int> top = q.front();
                q.pop();
                int xVal = top.first;
                int yVal = top.second;

                for (int i=0; i<4; i++){
                    int newX = xVal + x[i];
                    int newY = yVal + y[i];
                    if (newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                        q.push({newX,newY});
                        grid[newX][newY]=2;
                        freshOranges--;
                    }
                }
                size--;
            }
            time++;
       }
       if (freshOranges > 0){
        return -1;
       }
       if (time == -1){
        return 0;
       }
       return time;
    }
};
