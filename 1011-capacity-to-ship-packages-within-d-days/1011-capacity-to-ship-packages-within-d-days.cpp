class Solution {
public:
    
    bool isPossible(vector<int>w,int m,int d)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(m<w[i])
                return false;
            
            sum+=w[i];
            if(sum>m)
            {
                sum=w[i];
                days++;
            }
        }
        // cout<<days<<" ";
        if(days<=d)
            return true;
        else
            return false;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        long int l=0,h=0;
        int ans=INT_MAX;
        
        for(int i=0;i<weights.size();i++)
        {
         h+=weights[i];   
        }
        while(l<=h)
        {
            long int mid=l+(h-l)/2;
            bool c=isPossible(weights,mid,days);
            
            if(c==true)
            {
                if(mid<ans)
                ans=mid;
                
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};