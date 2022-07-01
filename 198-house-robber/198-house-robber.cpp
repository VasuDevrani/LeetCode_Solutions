class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        int a = 0; //for i<0
        int b = nums[0]; //for i=0
            
        for(int i=1;i<n;i++) //indexes shows the index of nums
        {
//             include case
            int incl = a + nums[i]; //i-1 of nums is i-2 of dp
//             exclude case
            int excl = b;
            
            int c = max(incl, excl);
            
            a = b;
            b = c;
        }
        
        return b;
    }
};