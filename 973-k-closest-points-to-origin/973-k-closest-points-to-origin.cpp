class Solution {
public:
    
    int dist(vector<int>v)
    {
        return (v[0]*v[0])+(v[1]*v[1]);
    }
    // ,vector<pair<int,int>>,greater<pair<int,int>>
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>q;
        
        for(int i=0;i<points.size();i++)
        {
            int d=dist(points[i]);
            cout<<d<<" ";
            q.push(make_pair(d,i));
            if(q.size()>k)
                q.pop();
        }
        
        vector<vector<int>>ans;
        
        while(!q.empty())
        {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        
        return ans;
    }
};