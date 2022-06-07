class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0)
            return;
        else if(nums1.size() == 0)
        {
            nums1 = nums2;
            return;
        }
        int i = 0,j = 0,k = 0;
        vector<int>ans(n+m);
        
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        }
        
        while(i<m)
        {
            ans[k++] = nums1[i++];
        }
        while(j<n)
        {
            ans[k++] = nums2[j++];
        }
        
        nums1 = ans;
    }
};