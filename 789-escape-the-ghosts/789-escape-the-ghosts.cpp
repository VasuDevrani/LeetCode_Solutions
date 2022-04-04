class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& g, vector<int>& t) {
        
         int dp=abs(t[0])+abs(t[1]);
         int n=g.size();
         for(int i=0;i<n;i++)
         {
             int temp=abs(g[i][0]-t[0])+abs(g[i][1]-t[1]);
             if(temp<=dp)
                  return false;
         }
       return true;
            
//         int dp=(t[0]*t[0])+(t[1]*t[1]);
//         cout<<dp<<endl;
        
//         for(int i=0;i<g.size();i++)
//         {
//             int temp=(g[i][0]-t[0])*(g[i][0]-t[0])+(g[i][1]-t[1])*(g[i][1]-t[1]);
//             cout<<temp<<" ";
//             if(temp<=dp){
//                 cout<<temp<<" "<<i;
//                 return false;
//             }
//         }
//         return true;
    }
};