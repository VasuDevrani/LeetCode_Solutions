class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n, 0);
        
        for(int i=0;i<roads.size();i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        
        priority_queue<int>q;
        
        for(int i=0;i<n;i++)
            q.push(indegree[i]);
        
        long long int ans = 0, i = n;
        while(!q.empty())
        {
            int top = q.top();
            ans += top*i;
            i--;
            q.pop();
        }
        
        return ans;
    }
};