class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
         if(6 * nums1.size() < 1 * nums2.size() || 6 * nums2.size() < 1 * nums1.size())
            return -1;
        
        int d = 0, opr = 0, j = 5;
        
        vector<int>arr(6);
        d = accumulate(begin(nums1), end(nums1), 0) - accumulate(begin(nums2), end(nums2), 0);
        
        if(d > 0) swap(nums1, nums2);
        
        for(int &num : nums1) arr[6 - num]++;  
        for(int &num : nums2) arr[num - 1]++;        
        d = abs(d);
        
        while(d > 0){
            if(arr[j]){
                opr += min(arr[j], (int)ceil(1.0 * d / j));
                d -= arr[j] * j;
                if(d <= 0)
                    return opr;                
            }
			j--;
		}
        return opr;
    }
};