class Solution {
public:
    vector<int>parent;
    
    int find_par(int node)
    {
        if(parent[node] == node)
            return node;
        else 
            return parent[node] = find_par(parent[node]);
    }

    void Union(int u, int v)
    {
        int pu = find_par(u) ; 
        int pv = find_par(v);
        
        parent[pu] = pv; 
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        parent.resize(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        
        for(int i=0;i<edges.size();i++)
        {
            Union(edges[i][0], edges[i][1]);
        }
        
        return find_par(src) == find_par(dest);
    }
};