class Solution {
public:
    
    void Utils(vector<vector<int>>& rooms,int *visited,int src){
        for (int i=0; i<rooms[src].size(); i++){
            if (visited[rooms[src][i]]==0 && src!=rooms[src][i]){
                visited[rooms[src][i]] = 1;
                Utils(rooms,visited,rooms[src][i]);     
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size();       
        int* visited = new int[m];
        
        for (int i=0; i<m; i++){
            visited[i]=0;
        }
        
        visited[0]=1;
        
        for (int i=0; i<m; i++){ 
            if (visited[i]==1){
                Utils(rooms,visited,i);
            }
        }
        
        
        for (int i=0; i<m; i++){
            if (visited[i]==0){
                return false;
            }
        }
        return true;
    }
};
