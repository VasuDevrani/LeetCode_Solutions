class Solution {
public:
    void dfs(vector<vector<int>>&graph, int node, vector<bool>&vis){
        
        vis[node] = true;
        
        for(int i=0; i<graph[node].size();i++)
        {
            if(!vis[graph[node][i]]){
                dfs(graph, graph[node][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        
        vector<bool> vis(n, false);
        
        dfs(rooms, 0, vis);
        
        for(i = 0; i < n; i++)
        {
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};