class Solution {
public:
    
   void is_valid(vector<vector<int>>& grid,int x,int y,int &countFreshOranges,queue<pair<int,int>> &qu){
    //if any of the condition is ture then we need to return back..
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==2 || grid[x][y]==0 ) return;
    
    grid[x][y]=2;
    countFreshOranges--;
    qu.push({x,y});  
}
  
int orangesRotting(vector<vector<int>>& grid) {

if(grid.empty()) return 0; // if there is no orange.

int n=grid.size();    
int m=grid[0].size();
queue<pair<int,int>> qu; // queue to store the index of the cell where rotten oranges are placed.

int countFreshOranges=0,time=0;   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2) qu.push({i,j});
            if(grid[i][j]==1) countFreshOranges++;    
        }
    }
if(countFreshOranges==0) return 0;    
 // four adjacent positions at which the oranged placed will get rotten.
 // vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
 while(!qu.empty()&& countFreshOranges != 0){
    time++; 
    int size=qu.size(); 
    for(int i=0;i<size;i++){
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        is_valid(grid,x,y+1,countFreshOranges,qu); 
        is_valid(grid,x,y-1,countFreshOranges,qu);
        is_valid(grid,x+1,y,countFreshOranges,qu); 
        is_valid(grid,x-1,y,countFreshOranges,qu);   
    }    
 }     
    if(countFreshOranges == 0 ) return time;
    else return -1;
}
};
