class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            vector<int> p = prerequisites[i];
            adj[p[0]].push_back(p[1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> rec(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] && isCycle(i, vis,rec, adj)) {
                return false; 
            }
        }
        return true;
    }
private: 
    bool isCycle(int src, vector<int>& vis, vector<int>& rec, vector<vector<int>>& adj) {
        if (rec[src]) return true;  
        if (vis[src]) return false;  
        vis[src] = 1;
        rec[src] = 1;
        for (int i=0; i<adj[src].size(); i++){
            if (isCycle(adj[src][i], vis,rec, adj)){
                return true;
            }
            
        }
        rec[src] = 0;
        return false;
    }
};
