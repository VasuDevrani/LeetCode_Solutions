class Solution {
public:
    
    bool bfs_check(vector<vector<int>>& graph, vector<int> &color, int n, int node)
    {   
        queue<int>q;
        q.push(node);
            
        while(!q.empty())
        {
            int parent = q.front();
            q.pop();
            
            for(auto nbr : graph[parent])
            {
                if(color[nbr] != -1 && color[nbr] == color[parent])
                    return true;
                else if(color[nbr] == -1)
                {
                    color[nbr] = (color[parent] == 0) ? 1 : 0;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
//         craete a color array
        vector<int>color(n, -1);
        
//         do bfs
        for(int src=0;src<n;src++){
            if(color[src] == -1){
                color[src] = 0;
                if(bfs_check(graph, color, n, src))
                    return false;
            }
        }
        
        return true;
    }
};