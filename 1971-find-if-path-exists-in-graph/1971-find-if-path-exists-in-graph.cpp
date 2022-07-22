class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
//         create the graph
        unordered_map<int,list<int>>adj;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
//         run a bfs from start node, if destination node exist in same graph component then its true else not
        
        queue<int>q;
        q.push(src);
        
        bool* visited = new bool[n];
        visited[src] = true;
        
        for(int i=0;i<n;i++)
            visited[i] = false;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(node == dest)
                return true;
            
            for(auto nbr : adj[node])
            {
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
};