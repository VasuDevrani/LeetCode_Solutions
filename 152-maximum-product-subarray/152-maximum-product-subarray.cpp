class Solution {
public:
//     prefix sum based dp solution
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int mx_Prod = 0;
        int cur_Prod = 1;
        int first_negative = 1;
        
        for(int i=0;i<n;i++)
        {
            cur_Prod *= nums[i];
            mx_Prod = max(mx_Prod, cur_Prod);
            
            if(cur_Prod < 0)
            {
                mx_Prod = max(mx_Prod, cur_Prod/first_negative);
                if(first_negative == 1)
                    first_negative = cur_Prod;
            }
            if(cur_Prod == 0)
            {
                first_negative = 1;
                cur_Prod = 1;
            }
        }
        return mx_Prod;
    }
};