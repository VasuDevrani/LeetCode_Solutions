class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int ct = 0;
        while(!q.empty())
        {
            int node = q.front();
            ct++;
            q.pop();
            
            for(auto nbr : adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        cout<<ct;
        return ct == n;
    }
};