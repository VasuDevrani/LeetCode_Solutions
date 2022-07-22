class Solution {
public:
    
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }
    
    int makeConnected(int n, vector<vector<int>>& edge) {
        
        if(edge.size() < n - 1)
            return -1;
        
        vector<vector<int>> adj(n);
        for(auto v : edge)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        
        int ct = 0;
        
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                ct++;
            }
        
        return ct - 1;
    }
};