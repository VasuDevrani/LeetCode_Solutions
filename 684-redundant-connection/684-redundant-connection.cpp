class Solution {
public:
    vector<int>parent;
    vector<int>Rank;
        
    int findPar(int node)
    {
        if(parent[node] == node)
            return node;
        else
            return parent[node] = findPar(parent[node]);
    }
    
    bool Union(int x, int y)
    {
        int p1 = findPar(x);
        int p2 = findPar(y);
        
        if(p1 == p2)
            return false;
        if(Rank[p1] == Rank[p2])
        {
            parent[p1] = p2;
            Rank[p2]++; 
        }
        else if(Rank[p1] < Rank[p2])
            parent[p1] = p2;
        else
            parent[p2] = p1;
        
        return true;
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        parent.resize(n+1);
        Rank.resize(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
            Rank[i] = 0;
        }
        
        for(auto e : edges)
        {
            if(!Union(e[0], e[1]))
                return e;
        }
        
        return { };
    }
};