class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(vector<vector<int>>& graph, vector<int>temp, int node)
    {
//         base case
        temp.push_back(node);
        
        if(node == graph.size()-1){
            ans.push_back(temp);
            return;
        }
            
//         recursive case
        // visited[node] = true;
        
        for(int i=0;i<graph[node].size();i++)
        {
            // if(!visited[graph[node][i]])
                dfs(graph, temp, graph[node][i]);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>temp;
        int n = graph.size();
        
//         bool* visited = new bool[n];
        
//         for(int i=0;i<n;i++)
//             visited[i] = false;
        
        dfs(graph, temp, 0);
        
        return ans;
    }
};