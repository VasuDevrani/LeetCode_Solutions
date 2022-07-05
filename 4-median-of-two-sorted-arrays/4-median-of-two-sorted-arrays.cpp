class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        int n = nums1.size(), m = nums2.size();
        
        vector<int>v;
        
        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]); 
                j++;
            }
        }
        
        while(i < n){
            v.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            v.push_back(nums2[j]);
            j++;
        }
        
        int mid = (n + m)/2;
        
        if((n+m)%2 == 0){
            return (v[mid] + v[mid-1])/2.0;
        }else{
            return v[mid];
        }
    }
};