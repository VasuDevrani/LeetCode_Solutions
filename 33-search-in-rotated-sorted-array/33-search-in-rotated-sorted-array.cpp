class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0, end=n-1;
        
        while(start<=end) {
            int mid=start + (end-start)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]<=nums[n-1]) {
                if(target>=nums[mid] && target<=nums[n-1]) 
                    start=mid+1;
                 else end=mid-1;                
            } else {
                if(target>=nums[0] && target<=nums[mid])
                    end=mid-1;
                 else start=mid+1;                
            }
        }
        return -1;
    }
//     int pivot_find(vector<int>v)
//     {
//         int l=0,h=v.size()-1;
//         while(l<h)
//         {
//             int mid=l+(h-l)/2;
//             if(v[mid]>=v[0])
//                 l=mid+1;
//             else 
//                 h=mid;
//         }
//         return l;
//     }
    
//     int search(vector<int>& nums, int target) {
//         int p=pivot_find(nums);
        
//         if(target==nums[p])
//             return p;
//         else if(target>nums[p] && target<nums[0])
//         {
//             int i= lower_bound(nums.begin()+p,nums.end(),target)-nums.begin();
//             if(nums[i]==target)
//                 return i;
//             else
//                 return -1;
//         }
//         else
//         {
//             int i= lower_bound(nums.begin(),nums.begin()+p-1,target)-nums.begin();
//             if(nums[i]==target)
//                 return i;
//             else
//                 return -1;
//         }
    
};