class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        long int ans = 0;
        
        for(int i=0;i<bt.size();i++)
        {
            swap(bt[i][0], bt[i][1]);
        }
        
        sort(bt.begin(),bt.end());
        
        for(int i=bt.size()-1;i>=0;i--)
        {
            if(ts <= 0)
                break;
            if(ts - bt[i][1] >= 0)
            {
                ans += bt[i][1] * bt[i][0];
                ts -= bt[i][1];
            }
            else{
                ans += ts * bt[i][0];
                ts = 0;
            }
        }
        
        return ans;
    }
};