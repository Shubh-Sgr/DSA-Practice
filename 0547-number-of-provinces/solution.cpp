class Solution {
public:
    
    void Utils(vector<vector<int>> isConnected,int *visited,int src){
        visited[src]=1;
        
        for (int i=0; i<isConnected[src].size(); i++){
            if (visited[i]==0 && src!=i && isConnected[src][i]==1){
                Utils(isConnected,visited,i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int* visited = new int[m];
        int count=0;
        
        for (int i=0; i<m; i++){
            visited[i]=0;
        }
        
        for (int i=0; i<m; i++)
        {
            if (visited[i]==0){
                Utils(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};
