class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        unordered_map<int, list<int>>adj, back;
        
        for(int i=0;i<conn.size();i++)
        {
            adj[conn[i][0]].push_back(conn[i][1]);
            back[conn[i][1]].push_back(conn[i][0]);
        }
        
        queue<int>q;
        bool* visited = new bool[n];
        
        for(int i=0;i<n;i++)
            visited[i] = false;
        
        q.push(0);
        visited[0] = true;
        
        int ans = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            visited[node] = true;
            q.pop();
            
            for(auto x : adj[node])
            {
                if(!visited[x]){
                    ans++;
                    q.push(x);
                }
            }
            
            for(auto x : back[node])
            {
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
        
        return ans;
    }
};