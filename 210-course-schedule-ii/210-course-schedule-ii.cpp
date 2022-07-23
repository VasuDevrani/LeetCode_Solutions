class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        
        vector<int>ans;
        
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
            ans.push_back(node);
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
        if(ct != n)
        {
            vector<int>temp;
            return temp;
        }
        
        return ans;
    }
};