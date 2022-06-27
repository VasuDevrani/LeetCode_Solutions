class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i = 0, j = 0;
        long int sum = accumulate(nums.begin(), nums.end(), 0);
        
        long int t = sum - x;
        if(sum < x)
            return -1;
        if(sum == x)
            return nums.size();
        
        long int temp = 0;
        int ans = 0, ct = 0;
        
        while(j <= nums.size())
        {
            if(temp == t){
                ans = max(ans, j-i);
                temp -= nums[i];
                i++;
                ct++;
            }
            if(temp < t){
                temp += nums[j];
                j++;
            }
            else if (temp > t){
                temp -= nums[i];
                i++;
            }
        }
        if(ct == 0)
            return -1;
        return nums.size() - ans;
    }
};