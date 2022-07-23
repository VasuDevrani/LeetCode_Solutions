class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
//         using kahn's algo (topo sort)
        
        int n = quiet.size();
        vector<int> indegree(n,0), ans(n,INT_MAX);
        
        vector<vector<int>> adj(n);
        queue<int> q;
        
        //build graph and calculate indegrees
        for(int i=0;i<richer.size();i++){
            adj[richer[i][0]].push_back(richer[i][1]);
            indegree[richer[i][1]]++;
        }
       
        for(int i=0;i<n;i++){
            ans[i] = i;
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i : adj[curr]){
                //if parent node having more money is quieter , update
                if(ans[i] == INT_MAX || quiet[ans[i]] > quiet[ans[curr]])
                    ans[i] = ans[curr];
                
                if(--indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans;
    }
};