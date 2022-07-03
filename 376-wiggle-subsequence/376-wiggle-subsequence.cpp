class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
//      COUNT THE NUMBER OF Ups AND Downs POINTS
        
        int n = nums.size();
        if(n == 1)
            return 1;
        
        int a = 1, b = 1;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1])
                a = b + 1;
            else if(nums[i] < nums[i-1])
                b = a + 1;
        }
        
        return max(a, b);
    }
};