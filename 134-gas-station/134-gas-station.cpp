class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit=0;
        int left=0;
        int start=0;
        
        for(int i=0;i<gas.size();i++)
        {
            left+=gas[i]-cost[i];
            if(left<0)
            {
                deficit+=left;
                start=i+1;
                left=0;
            }
        }
        if(deficit+left>=0)
            return start;
        else 
            return -1;
    }
};