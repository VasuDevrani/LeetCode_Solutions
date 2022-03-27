class Solution {
public:
    vector<int> decode(vector<int>& ec) {
        int n=ec.size();
        vector<int>ans;
         
        int x=0;
        for(int i=1;i<=n+1;i++)
        {
            x=x^i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i%2!=0)
            x=x^ec[i];
        }
        ans.push_back(x);
        for(int j=1;j<n+1;j++)
        {
            int y;
            y=ans[j-1]^ec[j-1];
            ans.push_back(y);
        }
         return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
        // if(n==2)
        // {
        //     ans.push_back(ec[1]);
        //     ans.push_back(ec[0]^ec[1]);
        //     ans.push_back(ec[0]);
        // }
        // else
        // {
        //     int i=n-1;
        //     while(i>0)   
        //     {
        //       if(i==n-1)
        //       {
        //           ans.push_back(ec[i]^ec[i-1]);
        //           i--;
        //       }
        //         else
        //         {
        //             ans.push_back(ec[i]);
        //             ans.push_back(ec[i]^ec[i-1]);
        //             i--;
        //         }
        //     }
        // }
    }
};