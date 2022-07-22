class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
//         solution by indegree array
        
        int indegree[n];
        for(int i=0;i<n;i++)
            indegree[i] = 0;
        
        for(int i=0;i<edges.size();i++)
            indegree[edges[i][1]]++;
        
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
                v.push_back(i);
        }
        
        return v;
    }
};