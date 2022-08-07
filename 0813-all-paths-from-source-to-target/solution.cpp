class Solution {
public:
    
    void Utils(vector<vector<int>>& graph,bool visited[],vector<int> temp,vector<vector<int>> &ans,int src,int dest){
        temp.push_back(src);
        // cout<<"before loop  "<<src<<" "<<dest<<" ";
        if (src==dest)
        {
            // cout<<"ok";
            ans.push_back(temp);
            return;
        }
        
        visited[src] = true;
        
        for (int i=0; i<graph[src].size(); i++){
            if (!visited[graph[src][i]]){
                // cout<<"in loop  "<<src<<" "<<graph[src][i]<<" ";
                Utils(graph,visited,temp,ans,graph[src][i],dest);
            }
        }
        
        visited[src] = false;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();
        
        bool visited[m];
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i=0; i<m; i++)
        {
            visited[i]=false;
        }
        
        Utils(graph,visited,temp,ans,0,m-1);
        
        return ans;
    }
};
