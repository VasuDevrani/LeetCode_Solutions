class Solution {
public:
    
    void dfs(bool visited[], int node, unordered_map<int, list<int>>&adj)
    {
        visited[node] = true;
        
        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
                dfs(visited, nbr, adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& ic) {
//         create adj list
        unordered_map<int, list<int>>adj;
        
        for(int i=0;i<ic.size();i++)
        {
            for(int j=0;j<ic[i].size();j++)
            {
                if(ic[i][j] == 1 && j != i)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
//         dfs and find number of components
        int n = ic.size();
        bool* visited = new bool[n+1];
        
        for(int i=1;i<=n;i++)
            visited[i] = false;
        
        int ct = 0;
        
        for(int src=1;src<=n;src++)
        {
            if(!visited[src]){
                cout<<src<<" ";
                dfs(visited, src, adj);
                ct++;
            }
        }
        
        return ct;
    }
};