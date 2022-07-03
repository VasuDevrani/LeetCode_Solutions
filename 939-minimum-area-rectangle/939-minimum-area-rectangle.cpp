class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        
//         storing the coordinates in map
        unordered_map<int,set<int>>m;
        
        for(int i=0;i<n;i++)
            m[points[i][0]].insert(points[i][1]);
        
//         now finding the rectangle and min area
        int Area = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j=i+1;j<n;j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
//                 check for the diagonals
                if(x1 != x2 && y1 != y2)
                {
//                     diagonal is present, check for other two points
                    if(m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x2].end())
                        Area = min(Area, abs((x2 - x1) * (y2 - y1)));
                }
            }
        }
              
        if(Area == INT_MAX)
              return 0;
        else
              return Area;
    }
};